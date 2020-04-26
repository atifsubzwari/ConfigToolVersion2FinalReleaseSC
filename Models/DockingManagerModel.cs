using ConfigGenerator.Helper;
using ConfigGenerator.Helpers;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using Logger = ConfigGenerator.Logging;

namespace ConfigGenerator.Models
{
    public class DockingManagerModel
    {
        public string Name { get; set; }

        public string Value { get; set; }
    }
    public static class DockingManagerModelHelper
    {
        public static AUTOSAR Configuration { get; set; }
        public static string ProjectName { get; set; }
        public static string ModuleName { get; set; }

        public static string SelectedMailBox { get; set; }
        public static string RootDirectory
        {
            get
            {
                if (Directory.GetCurrentDirectory().Contains("bin"))
                {
                    return Directory.GetCurrentDirectory().Substring(0, Directory.GetCurrentDirectory().IndexOf("\\bin"));
                }
                else
                {
                    return Directory.GetCurrentDirectory();
                }
            }
        }
        public static string TargetInputFolderPath
        {
            get
            {
                var ipFolder = Path.Combine(RootDirectory, "InputOutput", ProjectName, "InputFiles");
                if (!Directory.Exists(ipFolder))
                {
                    Directory.CreateDirectory(ipFolder);

                    // Copy all the required files from DefaultConfig to here
                    if (File.Exists(ipFolder + @"\CAN_Driver_cfg.h"))
                        File.Copy(ipFolder + @"\CAN_Driver_cfg.h", TargetOutputFolderPath + @"\CAN_Driver_cfg.h");
                }

                return ipFolder;
            }
        }
        public static string TargetOutputFolderPath
        {
            get
            {
                var opFolder = Path.Combine(RootDirectory, "InputOutput", ProjectName, "OutputFiles");
                if (!Directory.Exists(opFolder))
                    Directory.CreateDirectory(opFolder);

                return opFolder;
            }
        }
        public static void GenerateCantoolsConfigurations()
        {
            #region "CANDB Output Files Generation"
            run_cmd("\"" + RootDirectory + "\\Scripts\\call_cantools.py\"", "\"" + TargetInputFolderPath + "\\Sample_DB.dbc\"");
            CopyFiles(Directory.GetCurrentDirectory(), TargetOutputFolderPath);
            #endregion
        }

        public static void GenerateCantoolsConfigurationsTxt(String fileName)
        {
            #region "CANDB Output Files Generation"
            string fpath = "\"" + TargetInputFolderPath + "\\" + fileName + "\"";
           run_cmd("\"" + RootDirectory + "\\Scripts\\call_cantools.py\"", fpath);
           CopyFilesNew(Directory.GetCurrentDirectory(), TargetOutputFolderPath);
            run_cmd_txt("\"" + RootDirectory + "\\Scripts\\Canmang_final.py\"", "\"" + TargetInputFolderPath + "\\"+fileName+"\"", "\"" + TargetOutputFolderPath +"\\"+ fileName + "\"");
            string cfilename = fileName.Substring(0, fileName.Length-4);


          
            cfilename=cfilename + ".c";

            run_cmd_txt("\"" + RootDirectory + "\\Scripts\\master_file.py\"", "\"" + TargetOutputFolderPath + "\\" + cfilename + "\"", "\"" + TargetOutputFolderPath + "\\");

            try
            {
                File.Delete(Directory.GetCurrentDirectory() + "\\" + cfilename + ".c");
            }
            catch (Exception e) 
            {
                Logger.Log.Instance.Trace(e.Message);
            }

            try
            {
                File.Delete(Directory.GetCurrentDirectory() + "\\" + cfilename + ".h");
            }
            catch (Exception e)
            {
                Logger.Log.Instance.Trace(e.Message);
            }
            try
            {
                File.Delete(TargetOutputFolderPath + "\\" + cfilename + ".c");
            }
            catch (Exception e)
            {
                Logger.Log.Instance.Trace(e.Message);
            }

            try
            {
                File.Delete(TargetOutputFolderPath + "\\" + cfilename + ".h");
            }
            catch (Exception e)
            {
                Logger.Log.Instance.Trace(e.Message);
            }



            #endregion
        }

        private  static string SplitCamelCase(string inputCamelCaseString)
        {

            inputCamelCaseString= System.Text.RegularExpressions.Regex.Replace(inputCamelCaseString, "(.)([A-Z][a-z]+)", "\\1_\\2");
            inputCamelCaseString = System.Text.RegularExpressions.Regex.Replace(inputCamelCaseString, "(_+)", "_");
            inputCamelCaseString = System.Text.RegularExpressions.Regex.Replace(inputCamelCaseString, "([a-z0-9])([A-Z])", "\\1_\\2");
            inputCamelCaseString = System.Text.RegularExpressions.Regex.Replace(inputCamelCaseString, "[^a-zA-Z0-9]", "_");
           
            return inputCamelCaseString;


        }

        public static void GenerateConfigFile()
        {
            // Code for generating outputfiles from CANDB input file

            #region"Config File Generation"
            string[] lines = File.ReadAllLines(TargetInputFolderPath + "\\CAN_Driver_cfg.h");

            var currentPackage = DockingManagerModelHelper.Configuration.ARPACKAGES.Where(x => String.Equals(x.SHORTNAME.ToString().ToLower(), DockingManagerModelHelper.ModuleName.ToLower())).FirstOrDefault();

            Logger.Log.Instance.Info("Generating config file for " + DockingManagerModelHelper.ModuleName);

            for (int j = 0; j < currentPackage.ELEMENTS.ECUCMODULECONFIGURATIONVALUES.CONTAINERS.SUBCONTAINERS.Length; j++)
            {
                var currentConfigParamGrandParent = currentPackage.ELEMENTS.ECUCMODULECONFIGURATIONVALUES.CONTAINERS.SUBCONTAINERS[j];
                // TODO: Need to refine below code to accept only filtered object.
                for (int k = 0; k < currentConfigParamGrandParent.SUBCONTAINERS.Length; k++)
                {
                    List<string> lstSupportedValues = new List<string>();
                    string strControlType = string.Empty;
                    var currentConfigParamParent = currentConfigParamGrandParent.SUBCONTAINERS[k];

                    for (int x = 0; x < lines.Length; x++)
                    {
                        if (currentConfigParamParent.PARAMETERVALUES != null && lines[x].ToUpper().Contains(("#define " + currentConfigParamParent.PARAMETERVALUES.DEFINITIONREF.Value).ToUpper()))
                        {
                            lines[x] = string.Concat("#define ", currentConfigParamParent.PARAMETERVALUES.DEFINITIONREF.Value, "   ",
                                        currentConfigParamParent.PARAMETERVALUES.VALUE.SupplementaryValue, currentConfigParamParent.PARAMETERVALUES.VALUE.Value,
                                        currentConfigParamParent.PARAMETERVALUES.VALUE.Unit);
                            //break;
                        }
                    }

                    // foreach (var currentConfigParamChild in currentConfigParamParent.SUBCONTAINERS)
                    for (int i = 0; i < currentConfigParamParent.SUBCONTAINERS.Length; i++)
                    {
                        for (int x = 0; x < lines.Length; x++)
                        {
                            if (lines[x].ToUpper().Contains(("#define " + currentConfigParamParent.SUBCONTAINERS[i].PARAMETERVALUES.DEFINITIONREF.Value).ToUpper()))
                            {
                                lines[x] = string.Concat("#define ", currentConfigParamParent.SUBCONTAINERS[i].PARAMETERVALUES.DEFINITIONREF.Value, "   ",
                                            currentConfigParamParent.SUBCONTAINERS[i].PARAMETERVALUES.VALUE.SupplementaryValue, currentConfigParamParent.SUBCONTAINERS[i].PARAMETERVALUES.VALUE.Value,
                                            currentConfigParamParent.SUBCONTAINERS[i].PARAMETERVALUES.VALUE.Unit);
                               // break;
                            }
                        }
                    }
                }
            }

            File.WriteAllLines(TargetOutputFolderPath + "\\CAN_Driver_cfg.h", lines);

            Logger.Log.Instance.Info("Successfully generated CAN_Criver_cfg.h in the path: " + TargetOutputFolderPath);

            #endregion
        }

        public static AUTOSAR LoadARXML(bool isDefault)
        {
            Serializer ser = new Serializer();
            string path = string.Empty;

            if (string.IsNullOrEmpty(ProjectName))
                ProjectName = "DefaultConfig";

            // Check if there is Project specific ARXML file

            if (isDefault)
            {
                path = TargetInputFolderPath + "\\DefaultConfig.arxml";
            }
            else if (File.Exists(TargetOutputFolderPath + "\\DefaultConfig.arxml"))
            {
                // Found it and loading it
                path = TargetOutputFolderPath + "\\DefaultConfig.arxml";
            }
            else
            {
                // Load the default config ARXML
                path = Directory.GetCurrentDirectory() + @"\InputOutput\DefaultConfig\InputFiles\DefaultConfig.arxml";
            }

            Logger.Log.Instance.Info("Loading the ARXML file from path: " + path);

            string xmlInputData = File.ReadAllText(path);
            Configuration = ser.Deserialize<AUTOSAR>(xmlInputData);

            return Configuration;
        }

        public static void UpdateARXML()
        {
            string DirPath = string.Empty;
            Serializer ser = new Serializer();

            File.WriteAllText(TargetOutputFolderPath + "\\DefaultConfig.arxml", ser.Serialize(Configuration), System.Text.Encoding.UTF8);
            Logger.Log.Instance.Info("Updated the output ARXML in the path: " + TargetOutputFolderPath);
        }

        public static void run_cmd(string cmd, string args)
        {
            ProcessStartInfo start = new ProcessStartInfo();
            start.FileName = GetPythonPath();
            start.Arguments = string.Format("{0} {1}", cmd, args);
            start.UseShellExecute = false;
            start.RedirectStandardOutput = true;
            using (Process process = Process.Start(start))
            {
                using (StreamReader reader = process.StandardOutput)
                {
                    string result = reader.ReadToEnd();
                    Logger.Log.Instance.Info(" Successfully generated the ouput files for candb");
                }
            }
        }
        public static void run_cmd_txt(string cmd, string args,string output)
        {
            ProcessStartInfo start = new ProcessStartInfo();
            start.FileName = GetPythonPath();
            start.Arguments = string.Format("{0} {1} {2}", cmd, args, output);
            start.UseShellExecute = false;
            start.RedirectStandardOutput = true;
            using (Process process = Process.Start(start))
            {
                using (StreamReader reader = process.StandardOutput)
                {
                    string result = reader.ReadToEnd();
                    Logger.Log.Instance.Info(" Successfully generated the ouput files for candb");
                }
            }
        }

        public static string GetPythonPath()
        {
            IDictionary environmentVariables = Environment.GetEnvironmentVariables();
            string pathVariable = environmentVariables["Path"] as string;
            string pythonPathFromEnv = string.Empty;
            if (pathVariable != null)
            {
                string[] allPaths = pathVariable.Split(';');
                foreach (var path in allPaths)
                {
                    pythonPathFromEnv = path + "\\python.exe";
                    if (File.Exists(pythonPathFromEnv))
                        return pythonPathFromEnv;
                }
            }
            

            Logger.Log.Instance.Info(" Current Python path is " + pythonPathFromEnv);

            return pythonPathFromEnv;
        }
        public static void CopyFilesNew(string sourcePath, string targetPath)
        {
            string fileName = string.Empty;
            string destFile = string.Empty;
            FileInfo fi = new FileInfo(System.Reflection.Assembly.GetExecutingAssembly().Location);
            // To copy all the files in one directory to another directory. 
            // Get the files in the source folder. (To recursively iterate through 
            // all subfolders under the current directory, see 
            // "How to: Iterate Through a Directory Tree.")
            // Note: Check for target path was performed previously 
            //       in this code example. 
            if (System.IO.Directory.Exists(sourcePath))
            {
                string[] files = System.IO.Directory.GetFiles(sourcePath);

                // Copy the files and overwrite destination files if they already exist. 
                foreach (string s in files)
                {
                    // Use static Path methods to extract only the file name from the path.
                    fileName = System.IO.Path.GetFileName(s);
                    destFile = System.IO.Path.Combine(targetPath, fileName.Replace("_", ""));
                    if ((System.IO.Path.GetExtension(fileName).Equals(".h", StringComparison.OrdinalIgnoreCase)) || (System.IO.Path.GetExtension(fileName).Equals(".c", StringComparison.OrdinalIgnoreCase)))
                    {
                        System.IO.File.Copy(s, destFile, true);
                       
                        Logger.Log.Instance.Info(String.Format("Copied file {0} to {1}", s, destFile));
                        try
                        {
                            System.IO.File.Delete(s);
                        }
                        catch (Exception e)
                        {
                            Logger.Log.Instance.Trace(e.Message);
                        }
                    }
                }
            }
        }
        public static void CopyFiles(string sourcePath, string targetPath)
        {
            string fileName = string.Empty;
            string destFile = string.Empty;
            FileInfo fi = new FileInfo(System.Reflection.Assembly.GetExecutingAssembly().Location);
            // To copy all the files in one directory to another directory. 
            // Get the files in the source folder. (To recursively iterate through 
            // all subfolders under the current directory, see 
            // "How to: Iterate Through a Directory Tree.")
            // Note: Check for target path was performed previously 
            //       in this code example. 
            if (System.IO.Directory.Exists(sourcePath))
            {
                string[] files = System.IO.Directory.GetFiles(sourcePath);

                // Copy the files and overwrite destination files if they already exist. 
                foreach (string s in files)
                {
                    // Use static Path methods to extract only the file name from the path.
                    fileName = System.IO.Path.GetFileName(s);
                    destFile = System.IO.Path.Combine(targetPath, fileName.Replace("_",""));
                    if ((System.IO.Path.GetExtension(fileName).Equals(".h", StringComparison.OrdinalIgnoreCase)) || (System.IO.Path.GetExtension(fileName).Equals(".c", StringComparison.OrdinalIgnoreCase)))
                    {
                        System.IO.File.Copy(s, destFile, true);
                        Logger.Log.Instance.Info(String.Format("Copied file {0} to {1}", s, destFile));
                    }
                }
            }
        }
    }
}
