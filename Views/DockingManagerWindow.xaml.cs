using ConfigGenerator.Helper;
using ConfigGenerator.Helpers;
using ConfigGenerator.Models;
using Microsoft.Win32;
using Syncfusion.SfSkinManager;
using Syncfusion.Windows.Tools;
using Syncfusion.Windows.Tools.Controls;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using System.Web.Script.Serialization;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Forms.Integration;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using Logger = ConfigGenerator.Logging;
using WinForms = System.Windows.Forms;
using System.Collections;

namespace ConfigGenerator
{
    /// <summary>
    /// Interaction logic for Docking.xaml
    /// </summary>
    public partial class DockingManagerWindow : Window
    {

        #region Class Fields

        /// <summary>
        /// Class Fields
        /// </summary>

        private string m_strStoragePath = string.Format(@"{0}\ConfigGenerator.", Environment.CurrentDirectory);
        #endregion
        #region Fields
        private static string currentVisualStyle;
        private List<string> allNodes = new List<string>();
        private Dictionary<String, List<String>> txMessage = new Dictionary<string, List<string>>();
        private Dictionary<String, List<String>> rxMessage = new Dictionary<string, List<string>>();
        private Dictionary<String, String> rxReceptionTimeout = new Dictionary<string, string>();
        private Dictionary<String, String> rxmReceptionTimeout = null;
        private Dictionary<String, List<String>> txMessageWithFrameId = new Dictionary<string, List<string>>();
        private Dictionary<String, List<String>> rxMessageWithFrameId = new Dictionary<string, List<string>>();
        private Dictionary<String, String> messagesTxFrameIds = new Dictionary<string, string>();

        private Dictionary<String, String> messagesTxFrameIdsCanIf = new Dictionary<string, string>();
        private Dictionary<String, String> messagesRxFrameIds = new Dictionary<string, string>();
        private Dictionary<String, String> messagesRxFrameIdsCanIf = new Dictionary<string, string>();
        private Dictionary<String, String> messagesTxDLC = new Dictionary<string, string>();
        private Dictionary<String, String> messagesRxDLC = new Dictionary<string, string>();
        private Dictionary<String, String> messagesTxMethod = new Dictionary<string, string>();
        private Dictionary<String, String> messagesRxMethod = new Dictionary<string, string>();
        private Dictionary<String, String> messagesTxCycleTime = new Dictionary<string, string>();
        private Dictionary<String, String> messagesRxCycleTime = new Dictionary<string, string>();
        private Dictionary<String, String> messagesTxCounter = new Dictionary<string, string>();
        private Dictionary<String, String> messagesRxCounter = new Dictionary<string, string>();
        private Dictionary<String, List<String>> messagesTxSignal = new Dictionary<string, List<String>>();
        private Dictionary<String, List<String>> messagesRxSignal = new Dictionary<string, List<String>>();
        private Dictionary<String, List<String>> messagesIntitials = new Dictionary<string, List<String>>();
        private Dictionary<String, List<String>> messagesIntitialsFact = new Dictionary<string, List<String>>();
        private Dictionary<String, List<String>> messagesIntitialsOffset = new Dictionary<string, List<String>>();
        private Dictionary<String, List<String>> messagesLength = new Dictionary<string, List<String>>();
        private Dictionary<String, String> messagesTxInitialsConfig = new Dictionary<string, string>();
        private Dictionary<String, String> messagesExtended = new Dictionary<string, string>();
        private Dictionary<String, String> messagesTxScale = new Dictionary<string, string>();
        private Dictionary<String, String> messagesTxOffset = new Dictionary<string, string>();
        private Dictionary<String, String> messagesRxRange = new Dictionary<string, string>();
        private Dictionary<String, String> messagesRxScale = new Dictionary<string, string>();
        private Dictionary<String, String> messagesRxOffset = new Dictionary<string, string>();
        private Dictionary<String, String> rxReceptionTimeoutDefault = new Dictionary<string, string>();
        private Dictionary<String, String> rxReceptionTimeoutCallBack = new Dictionary<string, string>();
        private Dictionary<String, String> rxReceptionCallBackFunction = new Dictionary<string, string>();
        private string APPLICATION_WAKEUP_CBK;
        private string APPLICATION_NETWORK_REQUEST_CBK_FUNC;
        private string APPLICATION_BUSOFF_INDICATION;
        private string MAINFUNCTION_PERIOD;
        private List<string> headerFils = new List<string>();
        private List<string> headerFilsCanIf = new List<string>();

        private List<String> listCanIf = new List<string>();
        private List<String> lstMailConfigParentsMailBox = new List<string>();
        private Grid DynamicGridNew;
        private int staRow = 0;
        private Dictionary<String, String> mailBoxCanif = new Dictionary<string, string>();
        private Dictionary<String, String> mailBoxCanifNode = new Dictionary<string, string>();

        private Dictionary<String, List<String>> mailBoxCanifNodeMore = new Dictionary<string, List<string>>();

        private Dictionary<String, String> mailBoxMessage = new Dictionary<string, String>();
        private Dictionary<String, String> mailBoxFrameId = new Dictionary<string, String>();
        private Dictionary<String, String> mailBoxDLC = new Dictionary<string, String>();
        private Dictionary<String, String> mailBoxMaskValue = new Dictionary<string, String>();
        private Dictionary<String, String> mailBoxMessageRx = new Dictionary<string, String>();
        private Dictionary<String, String> mailBoxFrameIdRx = new Dictionary<string, String>();
        private Dictionary<String, String> mailBoxDLCRx = new Dictionary<string, String>();
        private Dictionary<String, String> mailBoxMaskValueRx = new Dictionary<string, String>();

        private Dictionary<String, List<String>> mailBoxMessageMore = new Dictionary<string, List<string>>();
        private Dictionary<String, List<String>> mailBoxFrameIdMore = new Dictionary<string, List<String>>();
        private Dictionary<String, List<String>> mailBoxDLCMore = new Dictionary<string, List<String>>();
        private Dictionary<String, List<String>> mailBoxMaskValueMore = new Dictionary<string, List<String>>();
        private Button btnAddMore;


        private Dictionary<String, List<String>> mailBoxMessageMoreRx = new Dictionary<string, List<string>>();
        private Dictionary<String, List<String>> mailBoxFrameIdMoreRx = new Dictionary<string, List<String>>();
        private Dictionary<String, List<String>> mailBoxDLCMoreRx = new Dictionary<string, List<String>>();
        private Dictionary<String, List<String>> mailBoxMaskValueMoreRx = new Dictionary<string, List<String>>();
        private Button btnAddMoreRx;
        private string fnamec = "";


        private string StateMachineTimeout = "";
        private string WaitforSleepTimeout = "";
        private string selectedNode = "";
        private string selectedTxMessage = "";
        private string selectedRxMessage = "";
        private string selectedSignal = "";
        private string selectedSignalRx = "";
        private string selectedType = "";

        private bool isManual = false;
        private string selectedMailBox = "";
        private string selectMailBoxMessage = "";
        private string selectMailBoxFrameId = "";
        private string selectMailBoxDLC = "";
        private string selectMailBoxMaskValue = "";
        private string selectedMailBoxRx = "";
        private string selectMailBoxMessageRx = "";
        private string selectMailBoxFrameIdRx = "";
        private string selectMailBoxDLCRx = "";
        private string selectMailBoxMaskValueRx = "";
        private string selectedMailCanIf = "";
        private bool isChanged = true;
        private string selectBackFunction = "";
        private string selectCallBack = "";
        private string selectTimeout = "";
        int buffertx = -1;
        int rxsigCount = 0;
        string[] alllines_encode;
        string[] alllines_unpack;
        string[] alllines_pack;
        string[] alllines_decode;
        string[] alllines_static;
        string[] alllines_range;

        List<Object> allObjects;

        #endregion

        #region Properties
        /// <summary>
        /// Gets or sets the current visual style.
        /// </summary>
        /// <value></value>
        /// <remarks></remarks>
        public string CurrentVisualStyle
        {
            get
            {
                return currentVisualStyle;
            }
            set
            {
                currentVisualStyle = value;
                OnVisualStyleChanged();
            }
        }
        #endregion

        #region Constructor
        /// <summary>
        /// Constructor for DockingManager.
        /// </summary>
        public DockingManagerWindow()
        {

            
            InitializeComponent();
            DockingManager.ActiveWindow = Can;
            InitWindowsFormsHost();
            SubscribeForEvents();
            this.Loaded += OnLoaded;
            listCanIf.Add("CANIF_UnusedCANMailbox");
            listCanIf.Add("CANIF_RxBasicCANMailbox");
            listCanIf.Add("CANIF_RxFullCANMailbox");
            listCanIf.Add("CANIF_TxBasicCANMailbox");
            listCanIf.Add("CANIF_TxFullCANMailbox");


            Logger.Log.Instance.Debug("Validating NLog");
            Logger.Log.Instance.Info("Info Validating NLog");

            try
            {
                DockingManagerModelHelper.run_cmd("\"" + DockingManagerModelHelper.RootDirectory + "\\Scripts\\packages.py\"", "");
                DockingManagerModelHelper.Configuration = DockingManagerModelHelper.LoadARXML(false);
                DockingManagerModelHelper.ProjectName = DockingManagerModelHelper.Configuration.ARPACKAGES[0].ELEMENTS.ECUCMODULECONFIGURATIONVALUES.DEFINITIONREF.Value;
                DockingManagerModelHelper.ModuleName = DockingManagerModelHelper.Configuration.ARPACKAGES[0].SHORTNAME;

                PopulateWorkspaceExplorer();
                if (File.Exists(DockingManagerModelHelper.TargetInputFolderPath + "\\CanMgrIF.txt"))
                {
                    DoDeSerialization();

                }
                if (File.Exists(DockingManagerModelHelper.TargetInputFolderPath + "\\updateddb.dbc"))
                {
                    DoCANManager("updateddb.dbc");

                }
                CreateDynamicWPFGridForModule();
                DoCanIf();



            }
            catch (Exception ex)
            {
                Logger.Log.Instance.Error("Exception encountered with message: " + ex.Message);

                throw ex;
            }
        }
        #endregion

        public void DoSerialization()
        {
            DoAddObjects();
            FileStream stream = new FileStream(DockingManagerModelHelper.TargetInputFolderPath + "\\CanMgrIF.txt", FileMode.OpenOrCreate);
            System.Runtime.Serialization.Formatters.Binary.BinaryFormatter formatter = new System.Runtime.Serialization.Formatters.Binary.BinaryFormatter();
            formatter.Serialize(stream, allObjects);

            stream.Close();
        }
        public void DoDeSerialization()
        {
            FileStream stream = new FileStream(DockingManagerModelHelper.TargetInputFolderPath + "\\CanMgrIF.txt", FileMode.OpenOrCreate);
            System.Runtime.Serialization.Formatters.Binary.BinaryFormatter formatter = new System.Runtime.Serialization.Formatters.Binary.BinaryFormatter();

            allObjects = (List<Object>)formatter.Deserialize(stream);
            if (allObjects != null)
            {
                allNodes = (List<string>)allObjects[0];
                txMessage = (Dictionary<string, List<string>>)allObjects[1];
                rxMessage = (Dictionary<string, List<string>>)allObjects[2];
                rxReceptionTimeout = (Dictionary<string, string>)allObjects[3];
                rxmReceptionTimeout = (Dictionary<string, string>)allObjects[4];
                txMessageWithFrameId = (Dictionary<string, List<string>>)allObjects[5];
                rxMessageWithFrameId = (Dictionary<string, List<string>>)allObjects[6];
                messagesTxFrameIds = (Dictionary<string, string>)allObjects[7];
                messagesTxFrameIdsCanIf = (Dictionary<string, string>)allObjects[8];
                messagesRxFrameIds = (Dictionary<string, string>)allObjects[9];
                messagesRxFrameIdsCanIf = (Dictionary<string, string>)allObjects[10];
                messagesTxDLC = (Dictionary<string, string>)allObjects[11];
                messagesRxDLC = (Dictionary<string, string>)allObjects[12];
                messagesTxMethod = (Dictionary<string, string>)allObjects[13]; ;
                messagesRxMethod = (Dictionary<string, string>)allObjects[14];
                messagesTxCycleTime = (Dictionary<string, string>)allObjects[15];
                messagesRxCycleTime = (Dictionary<string, string>)allObjects[16];
                messagesTxCounter = (Dictionary<string, string>)allObjects[17];
                messagesRxCounter = (Dictionary<string, string>)allObjects[18];
                messagesTxSignal = (Dictionary<string, List<string>>)allObjects[19];
                messagesRxSignal = (Dictionary<string, List<string>>)allObjects[20];
                messagesIntitials = (Dictionary<string, List<string>>)allObjects[21];
                messagesIntitialsFact = (Dictionary<string, List<string>>)allObjects[22];
                messagesIntitialsOffset = (Dictionary<string, List<string>>)allObjects[23];

                messagesTxInitialsConfig = (Dictionary<string, string>)allObjects[24];
                messagesExtended = (Dictionary<string, string>)allObjects[25];
                messagesTxScale = (Dictionary<string, string>)allObjects[26];
                messagesTxOffset = (Dictionary<string, string>)allObjects[27];
                messagesRxRange = (Dictionary<string, string>)allObjects[28];
                messagesRxScale = (Dictionary<string, string>)allObjects[29];
                messagesRxOffset = (Dictionary<string, string>)allObjects[30];
                rxReceptionTimeoutDefault = (Dictionary<string, string>)allObjects[31];
                rxReceptionTimeoutCallBack = (Dictionary<string, string>)allObjects[32];
                rxReceptionCallBackFunction = (Dictionary<string, string>)allObjects[33];
                APPLICATION_WAKEUP_CBK = (string)allObjects[34];
                APPLICATION_NETWORK_REQUEST_CBK_FUNC = (string)allObjects[35];
                APPLICATION_BUSOFF_INDICATION = (string)allObjects[36];
                MAINFUNCTION_PERIOD = (string)allObjects[37];
                headerFils = (List<string>)allObjects[38];
                headerFilsCanIf = (List<string>)allObjects[39];
                listCanIf = (List<string>)allObjects[40];
                lstMailConfigParentsMailBox = (List<string>)allObjects[41];
                staRow = (int)allObjects[42];
                mailBoxCanif = (Dictionary<string, string>)allObjects[43];
                mailBoxCanifNode = (Dictionary<string, string>)allObjects[44];
                mailBoxCanifNodeMore = (Dictionary<string, List<string>>)allObjects[45];
                mailBoxMessage = (Dictionary<string, string>)allObjects[46];
                mailBoxFrameId = (Dictionary<string, string>)allObjects[47];
                mailBoxDLC = (Dictionary<string, string>)allObjects[48];
                mailBoxMaskValue = (Dictionary<string, string>)allObjects[49];
                mailBoxMessageRx = (Dictionary<string, string>)allObjects[50];
                mailBoxFrameIdRx = (Dictionary<string, string>)allObjects[51];
                mailBoxDLCRx = (Dictionary<string, string>)allObjects[52];
                mailBoxMaskValueRx = (Dictionary<string, string>)allObjects[53];
                mailBoxMessageMore = (Dictionary<string, List<string>>)allObjects[54];
                mailBoxFrameIdMore = (Dictionary<string, List<string>>)allObjects[55];
                mailBoxDLCMore = (Dictionary<string, List<string>>)allObjects[56];
                mailBoxMaskValueMore = (Dictionary<string, List<string>>)allObjects[57];
                mailBoxMessageMoreRx = (Dictionary<string, List<string>>)allObjects[58];
                mailBoxFrameIdMoreRx = (Dictionary<string, List<string>>)allObjects[59];
                mailBoxDLCMoreRx = (Dictionary<string, List<string>>)allObjects[60];
                mailBoxMaskValueMoreRx = (Dictionary<string, List<string>>)allObjects[61];
                btnAddMoreRx = (Button)allObjects[62]; ;
                fnamec = (string)allObjects[63];

                StateMachineTimeout = (string)allObjects[64];
                WaitforSleepTimeout = (string)allObjects[65];
                selectedNode = (string)allObjects[66];
                selectedTxMessage = (string)allObjects[67];
                selectedRxMessage = (string)allObjects[68];
                selectedSignal = (string)allObjects[69];
                selectedSignalRx = (string)allObjects[70];
                selectedType = (string)allObjects[71];

                isManual = (bool)allObjects[72];
                selectedMailBox = (string)allObjects[73];
                selectMailBoxMessage = (string)allObjects[74];
                selectMailBoxFrameId = (string)allObjects[75];
                selectMailBoxDLC = (string)allObjects[76];
                selectMailBoxMaskValue = (string)allObjects[77];
                selectedMailBoxRx = (string)allObjects[78];
                selectMailBoxMessageRx = (string)allObjects[79];
                selectMailBoxFrameIdRx = (string)allObjects[80];
                selectMailBoxDLCRx = (string)allObjects[81];
                selectMailBoxMaskValueRx = (string)allObjects[82];
                selectedMailCanIf = (string)allObjects[83];
                isChanged = (bool)allObjects[84];
                selectBackFunction = (string)allObjects[85];
                selectCallBack = (string)allObjects[86];
                selectTimeout = (string)allObjects[87];
                buffertx = (int)allObjects[88];
                rxsigCount = (int)allObjects[89];
                alllines_encode = (string[])allObjects[90];
                alllines_unpack = (string[])allObjects[91];
                alllines_pack = (string[])allObjects[92];
                alllines_decode = (string[])allObjects[93];
                alllines_static = (string[])allObjects[94];
                alllines_range = (string[])allObjects[95];
                messagesLength = (Dictionary<string, List<string>>)allObjects[96];
            }


            stream.Close();
        }
        ~DockingManagerWindow()
        {
            DoSerialization();
        }

        public void DoAddObjects()
        {
            allObjects = new List<object>();
            allObjects.Add(allNodes);
            allObjects.Add(txMessage);
            allObjects.Add(rxMessage);
            allObjects.Add(rxReceptionTimeout);
            allObjects.Add(rxmReceptionTimeout);
            allObjects.Add(txMessageWithFrameId);
            allObjects.Add(rxMessageWithFrameId);
            allObjects.Add(messagesTxFrameIds);
            allObjects.Add(messagesTxFrameIdsCanIf);
            allObjects.Add(messagesRxFrameIds);
            allObjects.Add(messagesRxFrameIdsCanIf);
            allObjects.Add(messagesTxDLC);
            allObjects.Add(messagesRxDLC);
            allObjects.Add(messagesTxMethod);
            allObjects.Add(messagesRxMethod);
            allObjects.Add(messagesTxCycleTime);
            allObjects.Add(messagesRxCycleTime);
            allObjects.Add(messagesTxCounter);
            allObjects.Add(messagesRxCounter);
            allObjects.Add(messagesTxSignal);
            allObjects.Add(messagesRxSignal);
            allObjects.Add(messagesIntitials);
            allObjects.Add(messagesIntitialsFact);
            allObjects.Add(messagesIntitialsOffset);
            allObjects.Add(messagesTxInitialsConfig);
            allObjects.Add(messagesExtended);
            allObjects.Add(messagesTxScale);
            allObjects.Add(messagesTxOffset);
            allObjects.Add(messagesRxRange);
            allObjects.Add(messagesRxScale);
            allObjects.Add(messagesRxOffset);
            allObjects.Add(rxReceptionTimeoutDefault);
            allObjects.Add(rxReceptionTimeoutCallBack);
            allObjects.Add(rxReceptionCallBackFunction);
            allObjects.Add(APPLICATION_WAKEUP_CBK);
            allObjects.Add(APPLICATION_NETWORK_REQUEST_CBK_FUNC);
            allObjects.Add(APPLICATION_BUSOFF_INDICATION);
            allObjects.Add(MAINFUNCTION_PERIOD);
            allObjects.Add(headerFils);
            allObjects.Add(headerFilsCanIf);
            allObjects.Add(listCanIf);
            allObjects.Add(lstMailConfigParentsMailBox);
            allObjects.Add(staRow);
            allObjects.Add(mailBoxCanif);
            allObjects.Add(mailBoxCanifNode);
            allObjects.Add(mailBoxCanifNodeMore);
            allObjects.Add(mailBoxMessage);
            allObjects.Add(mailBoxFrameId);
            allObjects.Add(mailBoxDLC);
            allObjects.Add(mailBoxMaskValue);
            allObjects.Add(mailBoxMessageRx);
            allObjects.Add(mailBoxFrameIdRx);
            allObjects.Add(mailBoxDLCRx);
            allObjects.Add(mailBoxMaskValueRx);
            allObjects.Add(mailBoxMessageMore);
            allObjects.Add(mailBoxFrameIdMore);
            allObjects.Add(mailBoxDLCMore);
            allObjects.Add(mailBoxMaskValueMore);
            allObjects.Add(mailBoxMessageMoreRx);
            allObjects.Add(mailBoxFrameIdMoreRx);
            allObjects.Add(mailBoxDLCMoreRx);
            allObjects.Add(mailBoxMaskValueMoreRx);
            allObjects.Add(btnAddMoreRx);
            allObjects.Add(fnamec);
            allObjects.Add(StateMachineTimeout);
            allObjects.Add(WaitforSleepTimeout);
            allObjects.Add(selectedNode);
            allObjects.Add(selectedTxMessage);
            allObjects.Add(selectedRxMessage);
            allObjects.Add(selectedSignal);
            allObjects.Add(selectedSignalRx);
            allObjects.Add(selectedType);

            allObjects.Add(isManual);
            allObjects.Add(selectedMailBox);
            allObjects.Add(selectMailBoxMessage);
            allObjects.Add(selectMailBoxFrameId);
            allObjects.Add(selectMailBoxDLC);
            allObjects.Add(selectMailBoxMaskValue);
            allObjects.Add(selectedMailBoxRx);
            allObjects.Add(selectMailBoxMessageRx);
            allObjects.Add(selectMailBoxFrameIdRx);
            allObjects.Add(selectMailBoxDLCRx);
            allObjects.Add(selectMailBoxMaskValueRx);
            allObjects.Add(selectedMailCanIf);
            allObjects.Add(isChanged);
            allObjects.Add(selectBackFunction);
            allObjects.Add(selectCallBack);
            allObjects.Add(selectTimeout);
            allObjects.Add(buffertx);
            allObjects.Add(rxsigCount);
            allObjects.Add(alllines_encode);
            allObjects.Add(alllines_unpack);
            allObjects.Add(alllines_pack);
            allObjects.Add(alllines_decode);
            allObjects.Add(alllines_static);
            allObjects.Add(alllines_range);
            allObjects.Add(messagesLength);



        }

        #region "Dynamic Loading of Controls"
        private void PopulateWorkspaceExplorer()
        {
            String WorkspaceName = DockingManagerModelHelper.Configuration.ARPACKAGES[0].ELEMENTS.ECUCMODULECONFIGURATIONVALUES.DEFINITIONREF.Value.ToString().Trim('/').Split('/')[0];

            if (String.IsNullOrEmpty(WorkspaceName))
            {
                // We dont even the have the root node. Some thing wrong with the ARXML
                Logger.Log.Instance.Error("ARXML does not have even a single ARPACKAGE");
                MessageBox.Show("ARXML does not have even a single ARPACKAGE. Check the input ARXML");
                return;
            }

            // Let create the Tree which is just a holder for all the items and sub items
            TreeViewAdv wsTreeView = new TreeViewAdv();
            wsTreeView.SortingField = "Header";
            wsTreeView.Sorting = SortDirection.Ascending;
            wsTreeView.IsVirtualizing = true;
            wsTreeView.VirtualizationMode = Syncfusion.Windows.Tools.VirtualizationMode.Normal;
            wsTreeView.AnimationType = AnimationType.Fade;

            wsTreeView.SelectedItemChanged += wsTreeView_SelectedItemChanged;

            // Lets set the Workspace name
            TreeViewItemAdv tviWorkspace = new TreeViewItemAdv() { Header = WorkspaceName.ToString() };
            tviWorkspace.ExpandedImageSource = new BitmapImage(new Uri("/../Images/Folder_Expanded.png", UriKind.Relative));
            tviWorkspace.CollapsedImageSource = new BitmapImage(new Uri("/../Images/Folder_Collapsed.png", UriKind.Relative));
            tviWorkspace.IsExpanded = true;

            foreach (var ArPkg in DockingManagerModelHelper.Configuration.ARPACKAGES)
            {
                string modulename = ArPkg.SHORTNAME.ToString();
                TreeViewItemAdv tviModule = new TreeViewItemAdv() { Header = modulename };
                tviModule.Name = modulename;
                tviModule.LeftImageSource = new BitmapImage(new Uri("/../Images/" + modulename + "_MainModule_18px.png", UriKind.Relative));

                tviWorkspace.Items.Add(tviModule);
                Logger.Log.Instance.Info(String.Format("Added {0} module to the workspace view", modulename));
            }

            wsTreeView.Items.Add(tviWorkspace);

            WorkspacesExplorer.Content = wsTreeView;
        }
        //This method generates and loads the CAN Driver UI and values.
        private void CreateDynamicWPFGridForModule()
        {
            string modulename = DockingManagerModelHelper.ModuleName;

            var currentPackage = DockingManagerModelHelper.Configuration.ARPACKAGES.Where(x => String.Equals(x.SHORTNAME.ToString().ToLower(), modulename.ToLower())).FirstOrDefault();
            bool isParentAdded = false;

            if (modulename == DockingManagerModelHelper.ProjectName)
            {
                // User just clicked on the Project name. Ignore it
                return;
            }

            if (currentPackage == null)
            {
                MessageBox.Show(modulename + " DOES NOT exist  in the input ARXML file", "Error - Module not found");
                return;
            }

            // Clear any existing contents. This will help when we change modules
            SpForDynamicGrid.Children.Clear();

            // Create the Grid
            Grid DynamicGrid = new Grid();
            DynamicGrid.Width = 930;
            DynamicGrid.HorizontalAlignment = HorizontalAlignment.Left;
            DynamicGrid.VerticalAlignment = VerticalAlignment.Top;
            DynamicGrid.ShowGridLines = false;
            DynamicGrid.Name = modulename;

            // Create Columns
            ColumnDefinition gridCol1 = new ColumnDefinition();
            ColumnDefinition gridCol2 = new ColumnDefinition();
            ColumnDefinition gridCol3 = new ColumnDefinition();
            DynamicGrid.ColumnDefinitions.Add(gridCol1);
            DynamicGrid.ColumnDefinitions.Add(gridCol2);
            DynamicGrid.ColumnDefinitions.Add(gridCol3);

            int startrow = 0;
            int col = 0;
            List<string> lstMailConfigParents = new List<string>();


            for (int j = 0; j < currentPackage.ELEMENTS.ECUCMODULECONFIGURATIONVALUES.CONTAINERS.SUBCONTAINERS.Length; j++)
            {
                var currentConfigParamGrandParent = currentPackage.ELEMENTS.ECUCMODULECONFIGURATIONVALUES.CONTAINERS.SUBCONTAINERS[j];
                //TODO: Need to refine below code to accept only filtered object.
                for (int k = 0; k < currentConfigParamGrandParent.SUBCONTAINERS.Length; k++)
                {
                    List<string> lstSupportedValues = new List<string>();
                    string strControlType = string.Empty;
                    var currentConfigParamParent = currentConfigParamGrandParent.SUBCONTAINERS[k];

                    var areChildControlsEnabled = (currentConfigParamParent.PARAMETERVALUES == null) ? true : (currentConfigParamParent.PARAMETERVALUES.VALUE.Value.ToLower().Equals("enable") ? true : false);
                    var ChildControlsEnabledName = currentConfigParamParent.PARAMETERVALUES != null ? currentConfigParamParent.PARAMETERVALUES.DEFINITIONREF.name : "";
                    var ChildControlsEnabledText = currentConfigParamParent.PARAMETERVALUES != null ? currentConfigParamParent.PARAMETERVALUES.DEFINITIONREF.Value : "";
                    bool isEnableDisableCheckBoxAdded = false;

                    // foreach (var currentConfigParamChild in currentConfigParamParent.SUBCONTAINERS)
                    for (int i = 0; i < currentConfigParamParent.SUBCONTAINERS.Length; i++)
                    {
                        var currentConfigParamChild = currentConfigParamParent.SUBCONTAINERS[i];
                        var currentConfigParamName = currentConfigParamChild.PARAMETERVALUES.DEFINITIONREF.Value;
                        var currentConfigParamValue = currentConfigParamChild.PARAMETERVALUES.VALUE.Value;
                        var currentConfigParamID = currentConfigParamChild.PARAMETERVALUES.DEFINITIONREF.name;

                        // Everytime let's starts a new row from column index 0 
                        col = 0;

                        if (!isParentAdded && currentConfigParamGrandParent.SUBCONTAINERS.Length > 1)
                        {
                            // Populate mailbox list
                            lstMailConfigParents = currentConfigParamGrandParent.SUBCONTAINERS.Select(x => x.SHORTNAME).ToList();

                            var currSelectedMailBox = SpForDynamicGrid.Children
                                                        .OfType<ComboBox>()
                                                        .Where(cb => cb.Name == currentConfigParamGrandParent.SHORTNAME + "_Val")
                                                        .FirstOrDefault();

                            RowDefinition gridRowMailbox = new RowDefinition();
                            gridRowMailbox.Height = new GridLength(45);
                            DynamicGrid.RowDefinitions.Add(gridRowMailbox);

                            TextBlock lblMailBox = new TextBlock();
                            lblMailBox.Text = currentConfigParamGrandParent.SHORTNAME;
                            lblMailBox.Name = currentConfigParamGrandParent.SHORTNAME + "_LbL";
                            lblMailBox.FontFamily = new FontFamily("Calibri");
                            lblMailBox.FontSize = 14;
                            lblMailBox.VerticalAlignment = VerticalAlignment.Center;
                            lblMailBox.TextWrapping = TextWrapping.Wrap;
                            lblMailBox.ToolTip = currentConfigParamGrandParent.BRIEF.Trim();
                            Grid.SetRow(lblMailBox, startrow + i);
                            Grid.SetColumn(lblMailBox, col);
                            col++;
                            DynamicGrid.Children.Add(lblMailBox);

                            ComboBox drpDwnMailBox = new ComboBox();
                            drpDwnMailBox.Name = currentConfigParamGrandParent.SHORTNAME + "_Val";
                            drpDwnMailBox.FontSize = 12;
                            drpDwnMailBox.FontWeight = FontWeights.Bold;
                            drpDwnMailBox.Height = 30;
                            drpDwnMailBox.Background = Brushes.White;
                            drpDwnMailBox.IsSynchronizedWithCurrentItem = true;
                            drpDwnMailBox.SelectedIndex = currSelectedMailBox == null ? 0 : currSelectedMailBox.SelectedIndex;
                            drpDwnMailBox.SelectionChanged += drpDwnMailBox_SelectionChanged;
                            Grid.SetRow(drpDwnMailBox, startrow + i);
                            Grid.SetColumn(drpDwnMailBox, col);
                            col++;
                            drpDwnMailBox.ItemsSource = lstMailConfigParents;
                            if (lstMailConfigParents != null && lstMailConfigParents.Count > 0)
                            {
                                selectedMailBox = lstMailConfigParents[0];
                            }

                            DynamicGrid.Children.Add(drpDwnMailBox);

                            isParentAdded = true;
                        }


                        if (!isEnableDisableCheckBoxAdded)
                        {
                            RowDefinition gridRowCheckBox = new RowDefinition();
                            gridRowCheckBox.Height = new GridLength(45);
                            DynamicGrid.RowDefinitions.Add(gridRowCheckBox);
                            col = 0;
                            TextBlock lblChekBoxText = new TextBlock();
                            lblChekBoxText.Text = ChildControlsEnabledName;
                            lblChekBoxText.Name = ChildControlsEnabledName + "_Val";
                            lblChekBoxText.FontFamily = new FontFamily("Calibri");
                            lblChekBoxText.FontSize = 14;
                            lblChekBoxText.VerticalAlignment = VerticalAlignment.Center;
                            lblChekBoxText.TextWrapping = TextWrapping.Wrap;
                            lblChekBoxText.ToolTip = currentConfigParamGrandParent.BRIEF.Trim();

                            Grid.SetRow(lblChekBoxText, startrow + i + 1);
                            Grid.SetColumn(lblChekBoxText, col);
                            col++;
                            DynamicGrid.Children.Add(lblChekBoxText);

                            // Add the Checkbox to enable of disable this MailboxCtrl
                            CheckBox chkBoxEnableDisable = new CheckBox();
                            chkBoxEnableDisable.IsChecked = (currentConfigParamParent.PARAMETERVALUES == null) ? true : (currentConfigParamParent.PARAMETERVALUES.VALUE.Value.ToLower().Equals("enable") ? true : false);
                            chkBoxEnableDisable.FontSize = 12;
                            chkBoxEnableDisable.FontWeight = FontWeights.Bold;
                            chkBoxEnableDisable.Height = 15;
                            chkBoxEnableDisable.Margin = new Thickness(5, 0, 0, 0);
                            chkBoxEnableDisable.Name = currentConfigParamGrandParent.SHORTNAME + "_Val";
                            chkBoxEnableDisable.Background = Brushes.White;
                            chkBoxEnableDisable.Click += MailboxCtrl_Clicked;
                            Grid.SetRow(chkBoxEnableDisable, startrow + i + 1);
                            Grid.SetColumn(chkBoxEnableDisable, col);

                            Grid.SetColumn(chkBoxEnableDisable, col);
                            col++;

                            DynamicGrid.Children.Add(chkBoxEnableDisable);
                            isEnableDisableCheckBoxAdded = true;

                        }

                        RowDefinition gridRow = new RowDefinition();
                        gridRow.Height = new GridLength(45);
                        DynamicGrid.RowDefinitions.Add(gridRow);

                        TextBlock lbl = new TextBlock();

                        // Everytime let's starts a new row from column index 0 
                        col = 0;

                        if (currentConfigParamChild.PARAMETERVALUES.SUPPORTEDVALUES.SUPPORTEDVALUE == null || currentConfigParamChild.PARAMETERVALUES.SUPPORTEDVALUES.SUPPORTEDVALUE.Length == 1)
                        {
                            strControlType = "Textbox";
                        }
                        else if (currentConfigParamChild.PARAMETERVALUES.SUPPORTEDVALUES.SUPPORTEDVALUE.Length > 1)
                        {
                            lstSupportedValues = currentConfigParamChild.PARAMETERVALUES.SUPPORTEDVALUES.SUPPORTEDVALUE.ToList();
                            if (lstSupportedValues.Count > 0 && lstSupportedValues[0].Equals("Enable", StringComparison.OrdinalIgnoreCase))
                            {
                                strControlType = "Checkbox";
                            }
                            else
                            {
                                strControlType = "Combobox";
                            }
                        }

                        lbl.Name = currentConfigParamID;
                        lbl.Text = currentConfigParamName;
                        lbl.FontFamily = new FontFamily("Calibri");
                        lbl.FontSize = 14;
                        lbl.VerticalAlignment = VerticalAlignment.Center;
                        lbl.TextWrapping = TextWrapping.Wrap;
                        lbl.ToolTip = currentConfigParamChild.BRIEF.Trim();
                        if (isParentAdded)
                        {
                            Grid.SetRow(lbl, startrow + i + 2);
                        }
                        else
                        {
                            Grid.SetRow(lbl, startrow + i);
                        }
                        Grid.SetColumn(lbl, col);
                        col++;
                        DynamicGrid.Children.Add(lbl);

                        switch (strControlType)
                        {
                            case "Combobox":
                                ComboBox drpDwn = new ComboBox();
                                drpDwn.FontSize = 12;
                                drpDwn.FontWeight = FontWeights.Bold;
                                drpDwn.Height = 30;
                                drpDwn.Background = Brushes.White;
                                drpDwn.IsEnabled = areChildControlsEnabled;
                                drpDwn.Name = currentConfigParamID + "_Val";
                                drpDwn.IsSynchronizedWithCurrentItem = true;
                                if (isParentAdded)
                                {
                                    Grid.SetRow(drpDwn, startrow + i + 2);
                                }
                                else
                                {
                                    Grid.SetRow(drpDwn, startrow + i);
                                }
                                Grid.SetColumn(drpDwn, col);
                                col++;
                                drpDwn.ItemsSource = lstSupportedValues;
                                drpDwn.SelectedValue = currentConfigParamValue;

                                // Whenever CAN_DRIVER_MAILBOXx_INTERRUPT_CTRL(x=1…64)  checkbox is disabled,
                                // the child [INTERRUPT_PRIORITY] configurations should be greyed out so that user cannot select any values
                                if (currentConfigParamChild.PARAMETERVALUES.DEFINITIONREF.name.Contains("INTERRUPT_PRIORITY") &&
                                    currentConfigParamParent.SUBCONTAINERS[i - 1].PARAMETERVALUES.DEFINITIONREF.name.Contains("INTERRUPT_CTRL") &&
                                    currentConfigParamParent.SUBCONTAINERS[i - 1].PARAMETERVALUES.VALUE.Value.ToLower().Equals("disable"))
                                {
                                    drpDwn.IsEnabled = false;
                                }

                                DynamicGrid.Children.Add(drpDwn);
                                break;
                            case "Textbox":
                                TextBox txtBox = new TextBox();
                                txtBox.Text = currentConfigParamValue;
                                txtBox.FontSize = 12;
                                txtBox.FontWeight = FontWeights.Bold;
                                txtBox.Height = 30;
                                txtBox.Background = Brushes.White;
                                txtBox.IsEnabled = areChildControlsEnabled;
                                txtBox.Name = currentConfigParamID + "_Val";
                                txtBox.LostFocus += TxtBox_LostFocus;
                                if (isParentAdded)
                                {
                                    Grid.SetRow(txtBox, startrow + i + 2);
                                }
                                else
                                {
                                    Grid.SetRow(txtBox, startrow + i);
                                }
                                Grid.SetColumn(txtBox, col);
                                col++;
                                DynamicGrid.Children.Add(txtBox);
                                break;
                            case "Checkbox":
                                CheckBox chkBox = new CheckBox();
                                chkBox.IsChecked = currentConfigParamValue.ToString().Equals("ENABLE", StringComparison.OrdinalIgnoreCase) ? true : false;
                                chkBox.FontSize = 12;
                                chkBox.FontWeight = FontWeights.Bold;
                                chkBox.Height = 15;
                                chkBox.Background = Brushes.White;
                                chkBox.IsEnabled = areChildControlsEnabled;
                                chkBox.Name = currentConfigParamID + "_Val";
                                if (currentConfigParamID.Contains("INTERRUPT_CTRL"))
                                    chkBox.Click += ChkBox_Click;
                                if (isParentAdded)
                                {
                                    Grid.SetRow(chkBox, startrow + i + 2);
                                }
                                else
                                {
                                    Grid.SetRow(chkBox, startrow + i);
                                }

                                Grid.SetColumn(chkBox, col);
                                col++;
                                DynamicGrid.Children.Add(chkBox);
                                break;
                            default:
                                break;
                        }
                    }

                    startrow += currentConfigParamParent.SUBCONTAINERS.Length;
                    if (isParentAdded)
                        break;

                    // Add a splitter for each set of config values

                    //Separator sep = new Separator();
                    //sep.Background = Brushes.Red;
                    //sep.Height = 5;
                    //sep.Width = 150;
                    //Grid.SetRow(sep, startrow);
                    //DynamicGrid.Children.Add(sep);

                    startrow++;
                }
            }
            lstMailConfigParentsMailBox = lstMailConfigParents;
            staRow = startrow;
            //  DynamicGridNew = DynamicGrid;
            // DoCanIf();




            // Display grid into a Window
            SpForDynamicGrid.Children.Add(DynamicGrid);
        }

        //This method generates and loads the CAN Interface UI and values.
        private void DoCanIf()
        {
            // Clear any existing contents. This will help when we change modules
            SpForDynamicGridIf.Children.Clear();
            if (allObjects == null)
            {
                mailBoxCanif.Clear();
                buffertx = 0;

                mailBoxMessage.Clear();
                mailBoxFrameId.Clear();
                mailBoxDLC.Clear();
                mailBoxMaskValue.Clear();
                headerFilsCanIf.Clear();

                mailBoxMessageRx.Clear();
                mailBoxFrameIdRx.Clear();
                mailBoxDLCRx.Clear();
                mailBoxMaskValueRx.Clear();

                mailBoxMessageMore.Clear();
                mailBoxFrameIdMore.Clear();
                mailBoxDLCMore.Clear();
                mailBoxMaskValueMore.Clear();
                mailBoxCanifNode.Clear();

                mailBoxMessageMoreRx.Clear();
                mailBoxFrameIdMoreRx.Clear();
                mailBoxDLCMoreRx.Clear();
                mailBoxMaskValueMoreRx.Clear();
                WaitforSleepTimeout = "";
                StateMachineTimeout = "";
            }


            // Create the Grid
            Grid DynamicGrid = new Grid();
            DynamicGrid.Width = 930;
            DynamicGrid.HorizontalAlignment = HorizontalAlignment.Left;
            DynamicGrid.VerticalAlignment = VerticalAlignment.Top;
            DynamicGrid.ShowGridLines = false;
            DynamicGrid.Name = "CanIF";
            // Create Columns
            ColumnDefinition gridCol1 = new ColumnDefinition();
            ColumnDefinition gridCol2 = new ColumnDefinition();
            ColumnDefinition gridCol3 = new ColumnDefinition();


            DynamicGrid.ColumnDefinitions.Add(gridCol1);
            DynamicGrid.ColumnDefinitions.Add(gridCol2);
            DynamicGrid.ColumnDefinitions.Add(gridCol3);

            RowDefinition gridRowMailBox = new RowDefinition();
            gridRowMailBox.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowMailBox);
            TextBlock lblMailBox = new TextBlock();
            lblMailBox.Text = "Mail Box";
            lblMailBox.Name = "Mail_BOX" + "_LbL";
            lblMailBox.FontFamily = new FontFamily("Calibri");
            lblMailBox.FontSize = 14;
            lblMailBox.VerticalAlignment = VerticalAlignment.Center;
            lblMailBox.TextWrapping = TextWrapping.Wrap;
            lblMailBox.ToolTip = "Mail Box";
            Grid.SetRow(lblMailBox, 0);
            Grid.SetColumn(lblMailBox, 0);

            DynamicGrid.Children.Add(lblMailBox);

            ComboBox drpDwnMailBox = new ComboBox();
            drpDwnMailBox.Name = "Mail_BOX" + "_Val";
            drpDwnMailBox.FontSize = 12;
            drpDwnMailBox.FontWeight = FontWeights.Bold;
            drpDwnMailBox.Height = 30;
            drpDwnMailBox.Background = Brushes.White;
            drpDwnMailBox.IsSynchronizedWithCurrentItem = true;
            drpDwnMailBox.SelectedIndex = 0;

            Grid.SetRow(drpDwnMailBox, 0);
            Grid.SetColumn(drpDwnMailBox, 1);

            drpDwnMailBox.ItemsSource = lstMailConfigParentsMailBox;



            DynamicGrid.Children.Add(drpDwnMailBox);
            staRow++;


            RowDefinition gridRowCanIfMailbox = new RowDefinition();
            gridRowCanIfMailbox.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowCanIfMailbox);

            TextBlock lblCanIfMailBox = new TextBlock();
            lblCanIfMailBox.Text = "CAN IF Mail Box";
            lblCanIfMailBox.Name = "CAN_IF_Mail_Box" + "_LbL";
            lblCanIfMailBox.FontFamily = new FontFamily("Calibri");
            lblCanIfMailBox.FontSize = 14;
            lblCanIfMailBox.VerticalAlignment = VerticalAlignment.Center;
            lblCanIfMailBox.TextWrapping = TextWrapping.Wrap;
            lblCanIfMailBox.ToolTip = "CAN If Mail BOX";
            Grid.SetRow(lblCanIfMailBox, 1);
            Grid.SetColumn(lblCanIfMailBox, 0);

            DynamicGrid.Children.Add(lblCanIfMailBox);

            ComboBox drpDwnMailCanIfBox = new ComboBox();
            drpDwnMailCanIfBox.Name = "MailCanIFMail" + "_Val";
            drpDwnMailCanIfBox.FontSize = 12;
            drpDwnMailCanIfBox.FontWeight = FontWeights.Bold;
            drpDwnMailCanIfBox.Height = 30;
            drpDwnMailCanIfBox.Background = Brushes.White;
            drpDwnMailCanIfBox.IsSynchronizedWithCurrentItem = true;

            drpDwnMailCanIfBox.ItemsSource = listCanIf;

            drpDwnMailCanIfBox.SelectedIndex = 0;
            selectedMailCanIf = (string)drpDwnMailCanIfBox.SelectedItem;




            Grid.SetRow(drpDwnMailCanIfBox, 1);
            Grid.SetColumn(drpDwnMailCanIfBox, 1);

            DynamicGrid.Children.Add(drpDwnMailCanIfBox);
            DynamicGridNew = DynamicGrid;
            Button btnAddMoreButton = new Button();
            btnAddMoreButton.IsEnabled = false;
            btnAddMoreButton.Width = 70;
            btnAddMoreButton.Content = "Add More";
            btnAddMoreButton.Name = "btnAddMoreButton" + "_Val";
            btnAddMoreButton.FontSize = 12;
            btnAddMoreButton.FontWeight = FontWeights.Bold;
            btnAddMoreButton.Height = 30;
            btnAddMoreButton.Click += btnAddMoreButton_Clicked;
            Grid.SetRow(btnAddMoreButton, 1);
            Grid.SetColumn(btnAddMoreButton, 2);

            DynamicGrid.Children.Add(btnAddMoreButton);
            btnAddMore = btnAddMoreButton;



            RowDefinition gridRowNetWork = new RowDefinition();
            gridRowNetWork.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowNetWork);

            TextBlock lblNetworkNode = new TextBlock();
            lblNetworkNode.Text = "NetWork Nodes";
            lblNetworkNode.Name = "NetWork_Nodes" + "_LbL";
            lblNetworkNode.FontFamily = new FontFamily("Calibri");
            lblNetworkNode.FontSize = 14;
            lblNetworkNode.VerticalAlignment = VerticalAlignment.Center;
            lblNetworkNode.TextWrapping = TextWrapping.Wrap;
            lblNetworkNode.ToolTip = "NetWork Nodes".Trim();
            Grid.SetRow(lblNetworkNode, 2);
            Grid.SetColumn(lblNetworkNode, 0);

            DynamicGrid.Children.Add(lblNetworkNode);


            ComboBox drpDwnNetworkBox = new ComboBox();
            drpDwnNetworkBox.Name = "ComboNetworkNode" + "_Val";
            drpDwnNetworkBox.FontSize = 12;
            drpDwnNetworkBox.FontWeight = FontWeights.Bold;
            drpDwnNetworkBox.Height = 30;
            drpDwnNetworkBox.Background = Brushes.White;
            drpDwnNetworkBox.IsSynchronizedWithCurrentItem = true;
            drpDwnNetworkBox.SelectedIndex = 0;
            drpDwnNetworkBox.ItemsSource = allNodes.ToList();
            drpDwnNetworkBox.SelectionChanged += drpDwnNetworkBoxS_SelectionChanged;

            Grid.SetRow(drpDwnNetworkBox, 2);
            Grid.SetColumn(drpDwnNetworkBox, 1);
            DynamicGrid.Children.Add(drpDwnNetworkBox);

            RowDefinition gridRowMailTXFrameIdbox = new RowDefinition();
            gridRowMailTXFrameIdbox.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowMailTXFrameIdbox);

            TextBlock lblTxFrameIdBox = new TextBlock();
            lblTxFrameIdBox.Text = "Message FrameId";
            lblTxFrameIdBox.Name = "TX_MESSAGES" + "_LbL";
            lblTxFrameIdBox.FontFamily = new FontFamily("Calibri");
            lblTxFrameIdBox.FontSize = 14;
            lblTxFrameIdBox.VerticalAlignment = VerticalAlignment.Center;
            lblTxFrameIdBox.TextWrapping = TextWrapping.Wrap;
            lblTxFrameIdBox.ToolTip = "Message Frame Id";
            Grid.SetRow(lblTxFrameIdBox, 3);
            Grid.SetColumn(lblTxFrameIdBox, 0);

            DynamicGrid.Children.Add(lblTxFrameIdBox);
            if (fnamec != null && !fnamec.Trim().Equals(""))
            {
                ComboBox drpDwnMailTxFrameIdBox = new ComboBox();
                drpDwnMailTxFrameIdBox.Name = "MailTxSFrame" + "_Val";
                drpDwnMailTxFrameIdBox.FontSize = 12;
                drpDwnMailTxFrameIdBox.FontWeight = FontWeights.Bold;
                drpDwnMailTxFrameIdBox.Height = 30;
                drpDwnMailTxFrameIdBox.Background = Brushes.White;
                drpDwnMailTxFrameIdBox.IsSynchronizedWithCurrentItem = true;
                drpDwnMailTxFrameIdBox.IsEnabled = false;

                drpDwnMailTxFrameIdBox.SelectionChanged += drpDwnMailTxFrameIdBox_SelectionChanged;
                Grid.SetRow(drpDwnMailTxFrameIdBox, 3);
                Grid.SetColumn(drpDwnMailTxFrameIdBox, 1);
                DynamicGrid.Children.Add(drpDwnMailTxFrameIdBox);
            }
            else
            {
                TextBox txtBoxTXS = new TextBox();
                txtBoxTXS.Text = "";
                txtBoxTXS.FontSize = 12;
                txtBoxTXS.FontWeight = FontWeights.Bold;
                txtBoxTXS.Height = 30;
                txtBoxTXS.Background = Brushes.White;
                txtBoxTXS.TextChanged += txtBoxTXS_TextChanged;
                txtBoxTXS.Name = "MailTxS" + "_Val";
                txtBoxTXS.IsEnabled = false;
                Grid.SetRow(txtBoxTXS, 3);
                Grid.SetColumn(txtBoxTXS, 1);
                DynamicGrid.Children.Add(txtBoxTXS);
            }

            RowDefinition gridRowMailTXbox = new RowDefinition();
            gridRowMailTXbox.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowMailTXbox);
            TextBlock lblTxBox = new TextBlock();
            lblTxBox.Text = "Message";
            lblTxBox.Name = "TX_MESSAGES" + "_LbL";
            lblTxBox.FontFamily = new FontFamily("Calibri");
            lblTxBox.FontSize = 14;
            lblTxBox.VerticalAlignment = VerticalAlignment.Center;
            lblTxBox.TextWrapping = TextWrapping.Wrap;
            lblTxBox.ToolTip = "Message";
            Grid.SetRow(lblTxBox, 4);
            Grid.SetColumn(lblTxBox, 0);

            DynamicGrid.Children.Add(lblTxBox);
            List<String> onlyTx = new List<string>();
            if (fnamec != null && !fnamec.Trim().Equals(""))
            {
                ComboBox drpDwnMailTxBox = new ComboBox();
                drpDwnMailTxBox.Name = "MailTxS" + "_Val";
                drpDwnMailTxBox.FontSize = 12;
                drpDwnMailTxBox.FontWeight = FontWeights.Bold;
                drpDwnMailTxBox.Height = 30;
                drpDwnMailTxBox.Background = Brushes.White;
                drpDwnMailTxBox.IsSynchronizedWithCurrentItem = true;
                drpDwnMailTxBox.IsEnabled = false;


                drpDwnMailTxBox.SelectionChanged += drpDwnMailTxBox_SelectionChanged;
                Grid.SetRow(drpDwnMailTxBox, 4);
                Grid.SetColumn(drpDwnMailTxBox, 1);

                DynamicGrid.Children.Add(drpDwnMailTxBox);
            }
            else
            {
                TextBox txtBoxTXSM = new TextBox();
                txtBoxTXSM.Text = "";
                txtBoxTXSM.FontSize = 12;
                txtBoxTXSM.FontWeight = FontWeights.Bold;
                txtBoxTXSM.Height = 30;
                txtBoxTXSM.Background = Brushes.White;
                txtBoxTXSM.TextChanged += txtBoxTXSM_TextChanged;
                txtBoxTXSM.Name = "MailTxSM" + "_Val";
                txtBoxTXSM.IsEnabled = false;
                Grid.SetRow(txtBoxTXSM, 4);
                Grid.SetColumn(txtBoxTXSM, 1);
                DynamicGrid.Children.Add(txtBoxTXSM);
            }



            RowDefinition gridRowDLCTX = new RowDefinition();
            gridRowDLCTX.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowDLCTX);
            TextBlock lblDLCTX = new TextBlock();
            lblDLCTX.Text = "DLC";
            lblDLCTX.Name = "LBL_DLC_Value" + "_LbL";
            lblDLCTX.FontFamily = new FontFamily("Calibri");
            lblDLCTX.FontSize = 14;
            lblDLCTX.VerticalAlignment = VerticalAlignment.Center;
            lblDLCTX.TextWrapping = TextWrapping.Wrap;
            lblDLCTX.ToolTip = "DLC";
            Grid.SetRow(lblDLCTX, 5);
            Grid.SetColumn(lblDLCTX, 0);

            DynamicGrid.Children.Add(lblDLCTX);



            TextBox txtBoxDLC = new TextBox();
            if (onlyTx != null && onlyTx.Count > 0)
            {
                txtBoxDLC.Text = messagesTxDLC[onlyTx[0]];
                txtBoxDLC.IsEnabled = false;
            }
            else
            {
                txtBoxDLC.Text = "";
                txtBoxDLC.IsEnabled = true;
            }

            txtBoxDLC.FontSize = 12;
            txtBoxDLC.FontWeight = FontWeights.Bold;
            txtBoxDLC.Height = 30;
            txtBoxDLC.Background = Brushes.White;
            txtBoxDLC.TextChanged += txtBoxDLC_TextChanged;
            txtBoxDLC.Name = "txtMask" + "_Val";

            Grid.SetRow(txtBoxDLC, 5);
            Grid.SetColumn(txtBoxDLC, 1);
            DynamicGrid.Children.Add(txtBoxDLC);



            RowDefinition gridRowMaskValue = new RowDefinition();
            gridRowMaskValue.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowMaskValue);
            TextBlock lblMaskValueBox = new TextBlock();
            lblMaskValueBox.Text = "Mask Value";
            lblMaskValueBox.Name = "Mask_Value" + "_LbL";
            lblMaskValueBox.FontFamily = new FontFamily("Calibri");
            lblMaskValueBox.FontSize = 14;
            lblMaskValueBox.VerticalAlignment = VerticalAlignment.Center;
            lblMaskValueBox.TextWrapping = TextWrapping.Wrap;
            lblMaskValueBox.ToolTip = "Mask Value";

            Grid.SetRow(lblMaskValueBox, 6);
            Grid.SetColumn(lblMaskValueBox, 0);

            DynamicGrid.Children.Add(lblMaskValueBox);



            TextBox txtBoxMaskValue = new TextBox();
            txtBoxMaskValue.Text = "0";
            txtBoxMaskValue.FontSize = 12;
            txtBoxMaskValue.FontWeight = FontWeights.Bold;
            txtBoxMaskValue.Height = 30;
            txtBoxMaskValue.Background = Brushes.White;
            txtBoxMaskValue.TextChanged += txtBoxMaskValue_TextChanged;

            txtBoxMaskValue.Name = "txtMask" + "_Val";
            txtBoxMaskValue.IsEnabled = false;
            Grid.SetRow(txtBoxMaskValue, 6);
            Grid.SetColumn(txtBoxMaskValue, 1);
            DynamicGrid.Children.Add(txtBoxMaskValue);

            Button btnAddSubmit = new Button();
            btnAddSubmit.IsEnabled = true;
            btnAddSubmit.Width = 100;
            btnAddSubmit.Content = "Submit";
            btnAddSubmit.Name = "btnAddSubmit" + "_Val";
            btnAddSubmit.FontSize = 12;
            btnAddSubmit.FontWeight = FontWeights.Bold;
            btnAddSubmit.Height = 30;
            btnAddSubmit.Click += btnAddSubmit_Clicked;
            Grid.SetRow(btnAddSubmit, 6);
            Grid.SetColumn(btnAddSubmit, 2);
            btnAddSubmit.IsEnabled = false;
            DynamicGrid.Children.Add(btnAddSubmit);

            RowDefinition gridRowMore = new RowDefinition();
            gridRowMore.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowMore);
            TextBlock lblMoreFrame = new TextBlock();
            lblMoreFrame.Text = "Frameid";
            lblMoreFrame.Name = "More_frameId" + "_LbL";
            lblMoreFrame.FontFamily = new FontFamily("Calibri");
            lblMoreFrame.FontSize = 14;
            lblMoreFrame.VerticalAlignment = VerticalAlignment.Center;
            lblMoreFrame.TextWrapping = TextWrapping.Wrap;
            lblMoreFrame.ToolTip = "Frame Id";
            Grid.SetRow(lblMoreFrame, 7);
            Grid.SetColumn(lblMoreFrame, 0);

            DynamicGrid.Children.Add(lblMoreFrame);
            TextBlock lblMoreFrameMessage = new TextBlock();
            lblMoreFrameMessage.Text = "Message";
            lblMoreFrameMessage.Name = "More_frameId" + "_LbL";
            lblMoreFrameMessage.FontFamily = new FontFamily("Calibri");
            lblMoreFrameMessage.FontSize = 14;
            lblMoreFrameMessage.VerticalAlignment = VerticalAlignment.Center;
            lblMoreFrameMessage.TextWrapping = TextWrapping.Wrap;
            lblMoreFrameMessage.ToolTip = "Frame Id";
            Grid.SetRow(lblMoreFrameMessage, 7);
            Grid.SetColumn(lblMoreFrameMessage, 1);
            DynamicGrid.Children.Add(lblMoreFrameMessage);


            TextBlock lblMoreFrameMessageMaskValue = new TextBlock();
            lblMoreFrameMessageMaskValue.Text = "Mask Value";
            lblMoreFrameMessageMaskValue.Name = "More_frameIdMask" + "_LbL";
            lblMoreFrameMessageMaskValue.FontFamily = new FontFamily("Calibri");
            lblMoreFrameMessageMaskValue.FontSize = 14;
            lblMoreFrameMessageMaskValue.VerticalAlignment = VerticalAlignment.Center;
            lblMoreFrameMessageMaskValue.TextWrapping = TextWrapping.Wrap;
            lblMoreFrameMessageMaskValue.ToolTip = "Mask Value";
            Grid.SetRow(lblMoreFrameMessageMaskValue, 7);
            Grid.SetColumn(lblMoreFrameMessageMaskValue, 2);
            DynamicGrid.Children.Add(lblMoreFrameMessageMaskValue);



            Button btnAddRemove = new Button();
            btnAddRemove.IsEnabled = true;
            btnAddRemove.Width = 100;
            btnAddRemove.Content = "Remove";
            btnAddRemove.Name = "btnAddRemove" + "_Val";
            btnAddRemove.FontSize = 12;
            btnAddRemove.FontWeight = FontWeights.Bold;
            btnAddRemove.Height = 30;
            btnAddRemove.Click += btnRemoveSubmit_Clicked;
            Grid.SetRow(btnAddRemove, 7);
            Grid.SetColumn(btnAddRemove, 2);
            btnAddRemove.IsEnabled = false;
            DynamicGrid.Children.Add(btnAddRemove);

            RowDefinition gridRowMoreListRxFrameId = new RowDefinition();
            gridRowMoreListRxFrameId.Height = new GridLength(100);
            DynamicGrid.RowDefinitions.Add(gridRowMoreListRxFrameId);

            var panelTemplateTxFrameid = new ItemsPanelTemplate();
            var stackPanelTxFrameId = new FrameworkElementFactory(typeof(StackPanel));
            stackPanelTxFrameId.SetValue(StackPanel.OrientationProperty, Orientation.Vertical);
            panelTemplateTxFrameid.VisualTree = stackPanelTxFrameId;

            ListBox listBoxTxFrameId = new ListBox();
            listBoxTxFrameId.ItemsPanel = panelTemplateTxFrameid;

            listBoxTxFrameId.SetValue(Grid.RowProperty, 0);
            listBoxTxFrameId.SetValue(Grid.ColumnProperty, 0);
            listBoxTxFrameId.FontFamily = new FontFamily("Verdana");
            listBoxTxFrameId.FontSize = 12;

            listBoxTxFrameId.FontWeight = FontWeights.Bold;
            listBoxTxFrameId.Background = Brushes.White;
            Grid.SetRow(listBoxTxFrameId, 8);
            Grid.SetColumn(listBoxTxFrameId, 0);

            listBoxTxFrameId.SelectionChanged += listBoxTxFrameId_SelectionChanged;
            DynamicGrid.Children.Add(listBoxTxFrameId);


            var panelTemplateTxMessage = new ItemsPanelTemplate();
            var stackPanelTxMessage = new FrameworkElementFactory(typeof(StackPanel));
            stackPanelTxMessage.SetValue(StackPanel.OrientationProperty, Orientation.Vertical);
            panelTemplateTxMessage.VisualTree = stackPanelTxMessage;

            ListBox listBoxRxMessage = new ListBox();
            listBoxRxMessage.ItemsPanel = panelTemplateTxMessage;

            listBoxRxMessage.SelectionChanged += listBoxTx_SelectionChanged;
            listBoxRxMessage.SetValue(Grid.RowProperty, 0);
            listBoxRxMessage.SetValue(Grid.ColumnProperty, 0);
            listBoxRxMessage.FontFamily = new FontFamily("Verdana");
            listBoxRxMessage.FontSize = 12;

            listBoxRxMessage.FontWeight = FontWeights.Bold;
            listBoxRxMessage.Background = Brushes.White;
            Grid.SetRow(listBoxRxMessage, 8);
            Grid.SetColumn(listBoxRxMessage, 1);
            DynamicGrid.Children.Add(listBoxRxMessage);


            var panelTemplateTxMessageMaskValue = new ItemsPanelTemplate();
            var stackPanelTxMessageMaskValue = new FrameworkElementFactory(typeof(StackPanel));
            stackPanelTxMessageMaskValue.SetValue(StackPanel.OrientationProperty, Orientation.Vertical);
            panelTemplateTxMessageMaskValue.VisualTree = stackPanelTxMessageMaskValue;

            ListBox listBoxMaskValue = new ListBox();
            listBoxMaskValue.ItemsPanel = panelTemplateTxMessageMaskValue;

            listBoxMaskValue.SelectionChanged += listBoxMaskValue_SelectionChanged;
            listBoxMaskValue.SetValue(Grid.RowProperty, 0);
            listBoxMaskValue.SetValue(Grid.ColumnProperty, 0);
            listBoxMaskValue.FontFamily = new FontFamily("Verdana");
            listBoxMaskValue.FontSize = 12;

            listBoxMaskValue.FontWeight = FontWeights.Bold;
            listBoxMaskValue.Background = Brushes.White;
            Grid.SetRow(listBoxMaskValue, 8);
            Grid.SetColumn(listBoxMaskValue, 2);
            DynamicGrid.Children.Add(listBoxMaskValue);



            SpForDynamicGridIf.Children.Add(DynamicGrid);
            drpDwnMailBox.SelectionChanged += drpDwnMailBoxs_SelectionChanged;

            //drpDwnMailCanIfBox.SelectionChanged += drpDwnMailCanIfBox_SelectionChanged;
            drpDwnMailCanIfBox.SelectionChanged += drpDwnNetworkBoxS_SelectionChanged;



            RowDefinition gridRowStateMachineTimeoutLimit = new RowDefinition();
            gridRowStateMachineTimeoutLimit.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowStateMachineTimeoutLimit);


            TextBlock lblRowStateMachineTimeoutLimit = new TextBlock();
            lblRowStateMachineTimeoutLimit.Text = "State Machine Timeout Limit";
            lblRowStateMachineTimeoutLimit.Name = "StateMachineTimeoutLimit" + "_LbL";
            lblRowStateMachineTimeoutLimit.FontFamily = new FontFamily("Calibri");
            lblRowStateMachineTimeoutLimit.FontSize = 14;
            lblRowStateMachineTimeoutLimit.VerticalAlignment = VerticalAlignment.Center;
            lblRowStateMachineTimeoutLimit.TextWrapping = TextWrapping.Wrap;
            lblRowStateMachineTimeoutLimit.ToolTip = "AState Machine Timeout Limit".Trim();
            Grid.SetRow(lblRowStateMachineTimeoutLimit, 9);
            Grid.SetColumn(lblRowStateMachineTimeoutLimit, 0);

            DynamicGrid.Children.Add(lblRowStateMachineTimeoutLimit);


            TextBox txtBoxRowStateMachineTimeoutLimit = new TextBox();
            txtBoxRowStateMachineTimeoutLimit.Text = "";
            txtBoxRowStateMachineTimeoutLimit.FontSize = 12;
            txtBoxRowStateMachineTimeoutLimit.FontWeight = FontWeights.Bold;
            txtBoxRowStateMachineTimeoutLimit.Height = 30;
            txtBoxRowStateMachineTimeoutLimit.Background = Brushes.White;
            txtBoxRowStateMachineTimeoutLimit.TextChanged += txtBoxRowStateMachineTimeoutLimit_TextChanged;
            txtBoxRowStateMachineTimeoutLimit.Name = "txtBoxRowStateMachineTimeoutLimit" + "_Val";
            txtBoxRowStateMachineTimeoutLimit.IsEnabled = true;
            Grid.SetRow(txtBoxRowStateMachineTimeoutLimit, 9);
            Grid.SetColumn(txtBoxRowStateMachineTimeoutLimit, 1);

            DynamicGrid.Children.Add(txtBoxRowStateMachineTimeoutLimit);

            if (StateMachineTimeout != null)
            {
                txtBoxRowStateMachineTimeoutLimit.Text = StateMachineTimeout;
            }


            RowDefinition gridRowWaitforSleepTimeout = new RowDefinition();
            gridRowWaitforSleepTimeout.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowWaitforSleepTimeout);


            TextBlock lblWaitforSleepTimeout = new TextBlock();
            lblWaitforSleepTimeout.Text = "Wait for Sleep Timeout";
            lblWaitforSleepTimeout.Name = "MAINFUNCTION_PERIOD" + "_LbL";
            lblWaitforSleepTimeout.FontFamily = new FontFamily("Calibri");
            lblWaitforSleepTimeout.FontSize = 14;
            lblWaitforSleepTimeout.VerticalAlignment = VerticalAlignment.Center;
            lblWaitforSleepTimeout.TextWrapping = TextWrapping.Wrap;
            lblWaitforSleepTimeout.ToolTip = "WaitforSleepTimeout".Trim();
            Grid.SetRow(lblWaitforSleepTimeout, 10);
            Grid.SetColumn(lblWaitforSleepTimeout, 0);

            DynamicGrid.Children.Add(lblWaitforSleepTimeout);


            TextBox txtBoxWaitforSleepTimeout = new TextBox();
            txtBoxWaitforSleepTimeout.Text = "";
            txtBoxWaitforSleepTimeout.FontSize = 12;
            txtBoxWaitforSleepTimeout.FontWeight = FontWeights.Bold;
            txtBoxWaitforSleepTimeout.Height = 30;
            txtBoxWaitforSleepTimeout.Background = Brushes.White;
            txtBoxWaitforSleepTimeout.TextChanged += txtBoxWaitforSleepTimeout_TextChanged;
            txtBoxWaitforSleepTimeout.Name = "WaitforSleepTimeout" + "_Val";
            txtBoxWaitforSleepTimeout.IsEnabled = true;
            Grid.SetRow(txtBoxWaitforSleepTimeout, 10);
            Grid.SetColumn(txtBoxWaitforSleepTimeout, 1);

            DynamicGrid.Children.Add(txtBoxWaitforSleepTimeout);

            if (WaitforSleepTimeout != null)
            {
                txtBoxWaitforSleepTimeout.Text = WaitforSleepTimeout;
            }

            RowDefinition gridRowAddHeader = new RowDefinition();
            gridRowAddHeader.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowAddHeader);


            TextBlock lblHeader = new TextBlock();
            lblHeader.Text = "Header";
            lblHeader.Name = "Header" + "_LbL";
            lblHeader.FontFamily = new FontFamily("Calibri");
            lblHeader.FontSize = 14;
            lblHeader.VerticalAlignment = VerticalAlignment.Center;
            lblHeader.TextWrapping = TextWrapping.Wrap;
            lblHeader.ToolTip = "Header".Trim();
            Grid.SetRow(lblHeader, 11);
            Grid.SetColumn(lblHeader, 0);

            DynamicGrid.Children.Add(lblHeader);


            TextBox txtBoxHeader = new TextBox();
            txtBoxHeader.Text = "";
            txtBoxHeader.FontSize = 12;
            txtBoxHeader.FontWeight = FontWeights.Bold;
            txtBoxHeader.Height = 30;
            txtBoxHeader.Background = Brushes.White;

            txtBoxHeader.Name = "txtBoxHeader" + "_Val";
            txtBoxHeader.IsEnabled = true;
            Grid.SetRow(txtBoxHeader, 11);
            Grid.SetColumn(txtBoxHeader, 1);

            DynamicGrid.Children.Add(txtBoxHeader);
            RowDefinition gridRowAddHeaders = new RowDefinition();
            gridRowAddHeaders.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowAddHeaders);
            Button btnAddSubmitCanIf = new Button();
            btnAddSubmitCanIf.IsEnabled = true;
            btnAddSubmitCanIf.Width = 135;
            btnAddSubmitCanIf.Content = "Add Header Directive";
            btnAddSubmitCanIf.Name = "btnAddSubmit" + "_Val";
            btnAddSubmitCanIf.FontSize = 12;
            btnAddSubmitCanIf.FontWeight = FontWeights.Bold;
            btnAddSubmitCanIf.Height = 30;
            btnAddSubmitCanIf.Click += btnAddSubmitHeaderCanIf_Clicked;
            Grid.SetRow(btnAddSubmitCanIf, 11);
            Grid.SetColumn(btnAddSubmitCanIf, 2);

            DynamicGrid.Children.Add(btnAddSubmitCanIf);



            RowDefinition gridRowShowHeaders = new RowDefinition();
            gridRowShowHeaders.Height = new GridLength(100);
            DynamicGrid.RowDefinitions.Add(gridRowShowHeaders);

            var panelTemplateHeaders = new ItemsPanelTemplate();
            var stackPanelHeaders = new FrameworkElementFactory(typeof(StackPanel));
            stackPanelHeaders.SetValue(StackPanel.OrientationProperty, Orientation.Vertical);
            panelTemplateHeaders.VisualTree = stackPanelHeaders;

            ListBox listBoxHeader = new ListBox();
            listBoxHeader.ItemsPanel = panelTemplateHeaders;
          

            listBoxHeader.SetValue(Grid.RowProperty, 0);
            listBoxHeader.SetValue(Grid.ColumnProperty, 0);
            listBoxHeader.FontFamily = new FontFamily("Verdana");
            listBoxHeader.FontSize = 12;

            listBoxHeader.FontWeight = FontWeights.Bold;
            listBoxHeader.Background = Brushes.White;
            Grid.SetRow(listBoxHeader, 12);
            Grid.SetColumn(listBoxHeader,1);

            if(headerFilsCanIf!=null)
            {
                foreach(String hd in headerFilsCanIf)
                {
                    listBoxHeader.Items.Add(hd);
                }
            }

           
            DynamicGrid.Children.Add(listBoxHeader);

            Button btnAddRemoveHeader = new Button();
            btnAddRemoveHeader.IsEnabled = true;
            btnAddRemoveHeader.Width = 135;
            btnAddRemoveHeader.Content = "Remove Header";
            btnAddRemoveHeader.Name = "btnAddRemove" + "_Val";
            btnAddRemoveHeader.FontSize = 12;
            btnAddRemoveHeader.FontWeight = FontWeights.Bold;
            btnAddRemoveHeader.Height = 30;
            btnAddRemoveHeader.Click += btnRemoveSubmitHeder_Clicked;
            Grid.SetRow(btnAddRemoveHeader, 12);
            Grid.SetColumn(btnAddRemoveHeader, 2);
            btnAddRemove.IsEnabled = false;
            DynamicGrid.Children.Add(btnAddRemoveHeader);

            if (allObjects != null)
            {
                drpDwnMailBox.SelectedIndex = 1;
                drpDwnMailBox.SelectedIndex = 0;
                drpDwnMailBoxs_SelectionChanged(drpDwnMailBox, null);
            }


        }

        //This method generates and loads the CAN Manager UI and values.
        private void DoCANManager(String fileName)
        {
            string modulename = "StaticCanGrid";


            // Clear any existing contents. This will help when we change modules
            SpForDynamicGridStaticCan.Children.Clear();

            // Create the Grid
            Grid DynamicGrid = new Grid();
            DynamicGrid.Width = 1050;
            DynamicGrid.HorizontalAlignment = HorizontalAlignment.Left;
            DynamicGrid.VerticalAlignment = VerticalAlignment.Top;
            DynamicGrid.ShowGridLines = false;
            DynamicGrid.Name = modulename;

            // Create Columns
            ColumnDefinition gridCol1 = new ColumnDefinition();
            ColumnDefinition gridCol2 = new ColumnDefinition();
            ColumnDefinition gridCol3 = new ColumnDefinition();


            DynamicGrid.ColumnDefinitions.Add(gridCol1);
            DynamicGrid.ColumnDefinitions.Add(gridCol2);
            DynamicGrid.ColumnDefinitions.Add(gridCol3);
            if (allObjects == null)
            {
                fnamec = fileName.Substring(0, fileName.LastIndexOf("."));
                ConfigGenerator.Models.DockingManagerModelHelper.GenerateCantoolsConfigurationsTxt(fileName);


                allNodes.Clear();
                txMessage.Clear();
                rxMessage.Clear();
                txMessageWithFrameId.Clear();
                rxMessageWithFrameId.Clear();
                messagesTxFrameIds.Clear();
                messagesTxFrameIdsCanIf.Clear();
                messagesRxFrameIds.Clear();
                messagesRxFrameIdsCanIf.Clear();
                messagesTxDLC.Clear();
                messagesTxMethod.Clear();
                messagesRxMethod.Clear();
                messagesTxCycleTime.Clear();
                messagesTxCounter.Clear();
                messagesTxInitialsConfig.Clear();
                messagesTxScale.Clear();
                messagesTxOffset.Clear();
                messagesTxSignal.Clear();
                messagesIntitials.Clear();
                rxReceptionTimeout.Clear();
                messagesIntitialsFact.Clear();
                messagesIntitialsOffset.Clear();
                messagesLength.Clear();
                messagesRxDLC.Clear();
                messagesRxMethod.Clear();
                messagesRxMethod.Clear();
                messagesRxCycleTime.Clear();
                messagesRxCounter.Clear();
                messagesRxRange.Clear();
                messagesRxScale.Clear();
                messagesRxOffset.Clear();
                messagesRxSignal.Clear();

                messagesExtended.Clear();
                messagesIntitials.Clear();

                selectedRxMessage = "";
                selectedTxMessage = "";
                selectedNode = "";
                isManual = false;

                APPLICATION_WAKEUP_CBK = "";
                APPLICATION_NETWORK_REQUEST_CBK_FUNC = "";
                APPLICATION_BUSOFF_INDICATION = "";
                MAINFUNCTION_PERIOD = "";
                headerFils.Clear();

                List<string> lstNetWorkNodes = new List<string>();
                string[] alllines = File.ReadAllLines(DockingManagerModelHelper.TargetOutputFolderPath + "\\" + fileName + ".txt");
                // string[] alllines = File.ReadAllLines(DockingManagerModelHelper.TargetOutputFolderPath + "\\" +"innn" + ".txt");
                try
                {
                    alllines_encode = File.ReadAllLines(DockingManagerModelHelper.TargetOutputFolderPath + "\\encode.txt");
                    alllines_unpack = File.ReadAllLines(DockingManagerModelHelper.TargetOutputFolderPath + "\\unpack.txt");
                    alllines_pack = File.ReadAllLines(DockingManagerModelHelper.TargetOutputFolderPath + "\\pack.txt");
                    alllines_decode = File.ReadAllLines(DockingManagerModelHelper.TargetOutputFolderPath + "\\decode.txt");
                    alllines_static = File.ReadAllLines(DockingManagerModelHelper.TargetOutputFolderPath + "\\static.txt");
                    alllines_range = File.ReadAllLines(DockingManagerModelHelper.TargetOutputFolderPath + "\\range.txt");
                }
                catch (Exception ex)
                {
                    Logger.Log.Instance.Error("Exception encountered with message: " + ex.Message);

                    throw ex;
                }

                JavaScriptSerializer json_serializer = new JavaScriptSerializer();


                Object[] objArray = (Object[])json_serializer.DeserializeObject(alllines[0]);
                foreach (object o in objArray)
                {
                    allNodes.Add(o.ToString());
                }
                Dictionary<String, Object> tx = new Dictionary<string, object>();
                Object rx = new Object();
                Dictionary<String, Object> frameIdsTx = new Dictionary<string, object>();
                Dictionary<String, Object> frameIdsRx = new Dictionary<string, object>();
                Dictionary<String, Object> MethodTx = new Dictionary<string, object>();
                Dictionary<String, Object> MethodRx = new Dictionary<string, object>();
                Dictionary<String, Object> dlcTx = new Dictionary<string, object>();
                Dictionary<String, Object> dlcRx = new Dictionary<string, object>();
                Dictionary<String, Object> ctimeTx = new Dictionary<string, object>();
                Dictionary<String, Object> ctimeRx = new Dictionary<string, object>();
                Dictionary<String, Object> extend = new Dictionary<string, object>();
                Dictionary<String, Object> signalTx = new Dictionary<string, object>();
                Dictionary<String, Object> signalRx = new Dictionary<string, object>();
                Dictionary<String, Object> signalMsgInti = new Dictionary<string, object>();
                Dictionary<String, Object> signalMsgIntiFact = new Dictionary<string, object>();
                Dictionary<String, Object> signalMsgIntiOffset = new Dictionary<string, object>();
                Dictionary<String, Object> signalMsgLength = new Dictionary<string, object>();
                try
                {
                    String ext = alllines[12].Replace(":", ":\'").Replace(",", "\',").Replace("}", "\'}");
                    extend = (Dictionary<String, Object>)json_serializer.DeserializeObject(ext);

                }
                catch (Exception ex)
                {
                    Logger.Log.Instance.Error("Exception encountered with message: " + ex.Message);

                    throw ex;
                }
                try
                {
                    signalMsgInti = (Dictionary<String, Object>)json_serializer.DeserializeObject(alllines[11]);

                }
                catch (Exception e)
                {
                    String ini = alllines[11].Replace(", None", ",0");
                    signalMsgInti = (Dictionary<String, Object>)json_serializer.DeserializeObject(ini);
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                }

                try
                {
                    signalMsgIntiFact = (Dictionary<String, Object>)json_serializer.DeserializeObject(alllines[16]);

                }
                catch (Exception e)
                {
                    String iniFact = alllines[16].Replace(", None", ",0");
                    signalMsgIntiFact = (Dictionary<String, Object>)json_serializer.DeserializeObject(iniFact);
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);

                }
                try
                {
                    signalMsgIntiOffset = (Dictionary<String, Object>)json_serializer.DeserializeObject(alllines[17]);

                }
                catch (Exception e)
                {
                    String iniOffset = alllines[17].Replace(", None", ",0");
                    signalMsgIntiOffset = (Dictionary<String, Object>)json_serializer.DeserializeObject(iniOffset);
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);

                }
                try
                {
                    signalMsgLength = (Dictionary<String, Object>)json_serializer.DeserializeObject(alllines[18]);

                }
                catch (Exception e)
                {
                    String length = alllines[18].Replace(", None", ",0");
                    signalMsgLength = (Dictionary<String, Object>)json_serializer.DeserializeObject(length);
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);

                }
                try
                {
                    signalTx = (Dictionary<String, Object>)json_serializer.DeserializeObject(alllines[9]);

                }
                catch (Exception e)
                {
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                }
                try
                {
                    signalRx = (Dictionary<String, Object>)json_serializer.DeserializeObject(alllines[9]);

                }
                catch (Exception e)
                {
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                }

                try
                {
                    ctimeTx = (Dictionary<String, Object>)json_serializer.DeserializeObject(alllines[8]);

                }
                catch (Exception e)
                {
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                }
                try
                {
                    ctimeRx = (Dictionary<String, Object>)json_serializer.DeserializeObject(alllines[13]);

                }
                catch (Exception e)
                {
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                }
                try
                {
                    dlcTx = (Dictionary<String, Object>)json_serializer.DeserializeObject(alllines[4]);

                }
                catch (Exception e)
                {
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                }
                try
                {
                    dlcRx = (Dictionary<String, Object>)json_serializer.DeserializeObject(alllines[5]);

                }
                catch (Exception e)
                {
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                }
                try
                {
                    tx = (Dictionary<String, Object>)json_serializer.DeserializeObject(alllines[1]);

                }
                catch (Exception e)
                {
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                }
                try
                {
                    rx = (Object)json_serializer.DeserializeObject(alllines[2]);

                }
                catch (Exception e)
                {
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                }
                try
                {
                    frameIdsTx = (Dictionary<String, Object>)json_serializer.DeserializeObject(alllines[3]);

                }
                catch (Exception e)
                {
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                }
                try
                {
                    frameIdsRx = (Dictionary<String, Object>)json_serializer.DeserializeObject(alllines[10]);


                }
                catch (Exception e)
                {
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                }
                try
                {
                    MethodTx = (Dictionary<String, Object>)json_serializer.DeserializeObject(alllines[6]);

                }
                catch (Exception e)
                {
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                }
                try
                {
                    MethodRx = (Dictionary<String, Object>)json_serializer.DeserializeObject(alllines[7]);

                }
                catch (Exception e)
                {
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                }

                foreach (KeyValuePair<String, Object> sig in signalTx)
                {

                    Object[] objs = (Object[])sig.Value;
                    List<String> listSignal = new List<string>();
                    foreach (Object obj in objs)
                    {
                        listSignal.Add(obj.ToString().Trim());
                        if (!messagesTxInitialsConfig.ContainsKey(obj.ToString().Trim()))
                        {
                            //messagesTxInitialsConfig.Add(obj.ToString().Trim(), "0");
                        }
                        if (!messagesTxScale.ContainsKey(obj.ToString().Trim()))
                        {
                            messagesTxScale.Add(obj.ToString().Trim(), "0");
                        }
                        if (!messagesTxOffset.ContainsKey(obj.ToString().Trim()))
                        {
                            messagesTxOffset.Add(obj.ToString().Trim(), "0");
                        }


                    }
                    messagesTxSignal.Add(sig.Key.Trim(), listSignal);

                }


                foreach (KeyValuePair<String, Object> sig in signalRx)
                {

                    Object[] objs = (Object[])sig.Value;
                    List<String> listSignal = new List<string>();
                    foreach (Object obj in objs)
                    {
                        listSignal.Add(obj.ToString().Trim());
                        if (!messagesTxInitialsConfig.ContainsKey(obj.ToString().Trim()))
                        {
                            // messagesTxInitialsConfig.Add(obj.ToString().Trim(), "0");
                        }
                        if (!messagesTxScale.ContainsKey(obj.ToString().Trim()))
                        {
                            messagesTxScale.Add(obj.ToString().Trim(), "0");
                        }
                        if (!messagesTxOffset.ContainsKey(obj.ToString().Trim()))
                        {
                            messagesTxOffset.Add(obj.ToString().Trim(), "0");
                        }
                    }
                    messagesRxSignal.Add(sig.Key.Trim(), listSignal);

                }


                foreach (KeyValuePair<String, Object> sig in signalMsgInti)
                {

                    Object[] objs = (Object[])sig.Value;
                    List<String> listSignalInt = new List<string>();
                    foreach (Object obj in objs)
                    {
                        listSignalInt.Add(obj.ToString().Trim());

                    }
                    messagesIntitials.Add(sig.Key.Trim(), listSignalInt);

                }

                foreach (KeyValuePair<String, Object> sig in signalMsgIntiFact)
                {

                    Object[] objs = (Object[])sig.Value;
                    List<String> listSignalIntFact = new List<string>();
                    foreach (Object obj in objs)
                    {
                        listSignalIntFact.Add(obj.ToString().Trim());

                    }
                    messagesIntitialsFact.Add(sig.Key.Trim(), listSignalIntFact);

                }

                foreach (KeyValuePair<String, Object> sig in signalMsgIntiOffset)
                {

                    Object[] objs = (Object[])sig.Value;
                    List<String> listSignalIntOffset = new List<string>();
                    foreach (Object obj in objs)
                    {
                        listSignalIntOffset.Add(obj.ToString().Trim());

                    }
                    messagesIntitialsOffset.Add(sig.Key.Trim(), listSignalIntOffset);

                }
                foreach (KeyValuePair<String, Object> sig in signalMsgLength)
                {

                    Object[] objs = (Object[])sig.Value;
                    List<String> listSignalLength = new List<string>();
                    foreach (Object obj in objs)
                    {
                        listSignalLength.Add(obj.ToString().Trim());

                    }
                    messagesLength.Add(sig.Key.Trim(), listSignalLength);

                }


                foreach (KeyValuePair<String, Object> ctime in ctimeTx)
                {


                    messagesTxCycleTime.Add(ctime.Key, ctime.Value.ToString().Trim());


                }
                foreach (KeyValuePair<String, Object> ctime in ctimeRx)
                {


                    messagesRxCycleTime.Add(ctime.Key, ctime.Value.ToString().Trim());


                }

                foreach (KeyValuePair<String, Object> ext in extend)
                {


                    messagesExtended.Add(ext.Key.Trim(), ext.Value.ToString().Trim());


                }

                foreach (KeyValuePair<String, Object> fid in frameIdsTx)
                {


                    messagesTxFrameIds.Add(fid.Key, fid.Value.ToString().Trim());
                    messagesTxFrameIdsCanIf.Add(fid.Key, fid.Value.ToString().Trim());


                }
                foreach (KeyValuePair<String, Object> fid in frameIdsRx)
                {


                    messagesRxFrameIds.Add(fid.Key.Trim(), fid.Value.ToString().Trim());
                    messagesRxFrameIdsCanIf.Add(fid.Key.Trim(), fid.Value.ToString().Trim());


                }
                foreach (KeyValuePair<String, Object> dlc in dlcTx)
                {


                    messagesTxDLC.Add(dlc.Key, dlc.Value.ToString().Trim());


                }
                foreach (KeyValuePair<String, Object> dlc in dlcRx)
                {


                    messagesRxDLC.Add(dlc.Key, dlc.Value.ToString().Trim());


                }

                foreach (KeyValuePair<String, Object> mthd in MethodTx)
                {
                    string txm = mthd.Value.ToString().Trim();

                    if (txm.Equals("Combined(Event/Periodic)"))
                    {
                        txm = "Combined";

                    }

                    messagesTxMethod.Add(mthd.Key.Trim(), txm);


                }
                foreach (KeyValuePair<String, Object> mthd in MethodRx)
                {
                    string rxm = mthd.Value.ToString().Trim();

                    if (rxm.Equals("Combined(Event/Periodic)"))
                    {
                        rxm = "Combined";

                    }

                    messagesRxMethod.Add(mthd.Key.Trim(), rxm);


                }
                foreach (KeyValuePair<String, Object> t in tx)
                {

                    Object[] objs = (Object[])t.Value;
                    List<string> listTxMessage = new List<string>();
                    List<string> listTxMessageWithFameId = new List<string>();
                    foreach (object obj in objs)
                    {
                        String svalue = "";
                        messagesTxFrameIds.TryGetValue(obj.ToString(), out svalue);

                        listTxMessageWithFameId.Add(obj.ToString() + "(" + svalue + ")");
                        listTxMessage.Add(obj.ToString());
                    }
                    txMessageWithFrameId.Add(t.Key, listTxMessageWithFameId);
                    txMessage.Add(t.Key, listTxMessage);


                }


                if (rx != null)
                {


                    Object[] objs = (Object[])rx;

                    if (objs != null && objs.Length > 0)
                    {
                        foreach (object ob in objs)
                        {
                            Object[] obNodeValues = (Object[])ob;
                            string rxValue = obNodeValues[0].ToString();
                            Object[] nodes = (Object[])obNodeValues[1];
                            foreach (Object nodeObject in nodes)
                            {
                                String node = (String)nodeObject;
                                if (rxMessage.ContainsKey(node))
                                {
                                    List<String> rxm = new List<string>();
                                    List<String> rxmFrmeId = new List<string>();

                                    rxMessage.TryGetValue(node, out rxm);
                                    rxMessageWithFrameId.TryGetValue(node, out rxmFrmeId);


                                    if (!rxm.Contains(rxValue))
                                    {
                                        rxm.Add(rxValue);
                                        String frmaeid = "";
                                        messagesRxFrameIds.TryGetValue(rxValue, out frmaeid);
                                        rxmFrmeId.Add(rxValue + "(" + frmaeid + ")");

                                    }
                                }
                                else
                                {
                                    List<String> rxm = new List<string>();
                                    List<String> rxmFrmeId = new List<string>();


                                    rxm.Add(rxValue);
                                    String frmaeid = "";
                                    messagesRxFrameIds.TryGetValue(rxValue, out frmaeid);
                                    rxmFrmeId.Add(rxValue + "(" + frmaeid + ")");
                                    rxMessage.Add(node, rxm);
                                    rxMessageWithFrameId.Add(node, rxmFrmeId);
                                }
                            }
                        }
                    }
                }
            }



            string snode = selectedNode;
            RowDefinition gridRowNetWork = new RowDefinition();
            gridRowNetWork.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowNetWork);

            TextBlock lblNetworkNode = new TextBlock();
            lblNetworkNode.Text = "Network Nodes";
            lblNetworkNode.Name = "NetWork_Nodes" + "_LbL";
            lblNetworkNode.FontFamily = new FontFamily("Calibri");
            lblNetworkNode.FontSize = 14;
            lblNetworkNode.VerticalAlignment = VerticalAlignment.Center;
            lblNetworkNode.TextWrapping = TextWrapping.Wrap;
            lblNetworkNode.ToolTip = "Network Nodes from DBC".Trim();
            Grid.SetRow(lblNetworkNode, 0);
            Grid.SetColumn(lblNetworkNode, 0);

            DynamicGrid.Children.Add(lblNetworkNode);


            ComboBox drpDwnNetworkBox = new ComboBox();
            drpDwnNetworkBox.Name = "ComboNetworkNode" + "_Val";
            drpDwnNetworkBox.FontSize = 12;
            drpDwnNetworkBox.FontWeight = FontWeights.Bold;
            drpDwnNetworkBox.Height = 30;
            drpDwnNetworkBox.Background = Brushes.White;
            drpDwnNetworkBox.IsSynchronizedWithCurrentItem = true;
            drpDwnNetworkBox.SelectedIndex = 0;
            drpDwnNetworkBox.ItemsSource = allNodes.ToList();
            drpDwnNetworkBox.SelectionChanged += drpDwnNetworkBox_SelectionChanged;

            Grid.SetRow(drpDwnNetworkBox, 0);
            Grid.SetColumn(drpDwnNetworkBox, 1);
            selectedNode = allNodes[0];
            DynamicGrid.Children.Add(drpDwnNetworkBox);

            RowDefinition gridRowNetWorkNode = new RowDefinition();
            gridRowNetWorkNode.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowNetWorkNode);
            TextBlock lblTxNetworkNode = new TextBlock();
            lblTxNetworkNode.Text = "Tx Messages";
            lblTxNetworkNode.Name = "Tx_Messages" + "_LbL";
            lblTxNetworkNode.FontFamily = new FontFamily("Calibri");
            lblTxNetworkNode.FontSize = 14;
            lblTxNetworkNode.VerticalAlignment = VerticalAlignment.Center;
            lblTxNetworkNode.TextWrapping = TextWrapping.Wrap;
            lblTxNetworkNode.ToolTip = "Tx Messages".Trim();
            Grid.SetRow(lblTxNetworkNode, 1);
            Grid.SetColumn(lblTxNetworkNode, 0);
            DynamicGrid.Children.Add(lblTxNetworkNode);


            ComboBox drpDwnTxNetworkBox = new ComboBox();
            drpDwnTxNetworkBox.Name = "ComboNetworkNodeTx" + "_Val";
            drpDwnTxNetworkBox.FontSize = 12;
            drpDwnTxNetworkBox.FontWeight = FontWeights.Bold;
            drpDwnTxNetworkBox.Height = 30;
            drpDwnTxNetworkBox.Background = Brushes.White;
            drpDwnTxNetworkBox.IsSynchronizedWithCurrentItem = true;
            drpDwnTxNetworkBox.SelectedIndex = 0;
            Grid.SetRow(drpDwnTxNetworkBox, 1);
            Grid.SetColumn(drpDwnTxNetworkBox, 1);



            List<String> lvaluesTx = new List<String>();
            txMessageWithFrameId.TryGetValue(allNodes[0], out lvaluesTx);
            if (lvaluesTx != null)
            {
                drpDwnTxNetworkBox.ItemsSource = lvaluesTx.ToList();
                drpDwnTxNetworkBox.SelectionChanged += drpDwnTxNetworkBox_SelectionChanged;

            }
            else
            {
                lvaluesTx = new List<String>();
                drpDwnTxNetworkBox.ItemsSource = lvaluesTx.ToList();
            }
            DynamicGrid.Children.Add(drpDwnTxNetworkBox);

            RowDefinition gridRowSignal = new RowDefinition();
            gridRowSignal.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowSignal);

            TextBlock lblSignal = new TextBlock();
            lblSignal.Text = "TX Signals";
            lblSignal.Name = "Signal" + "_LbL";
            lblSignal.FontFamily = new FontFamily("Calibri");
            lblSignal.FontSize = 14;
            lblSignal.VerticalAlignment = VerticalAlignment.Center;
            lblSignal.TextWrapping = TextWrapping.Wrap;
            lblSignal.ToolTip = "Tx Signals".Trim();
            Grid.SetRow(lblSignal, 2);
            Grid.SetColumn(lblSignal, 0);
            DynamicGrid.Children.Add(lblSignal);


            ComboBox drpDwnSignal = new ComboBox();
            drpDwnSignal.Name = "ComboSignal" + "_Val";
            drpDwnSignal.FontSize = 12;
            drpDwnSignal.FontWeight = FontWeights.Bold;
            drpDwnSignal.Height = 30;
            drpDwnSignal.Background = Brushes.White;
            drpDwnSignal.IsSynchronizedWithCurrentItem = true;
            drpDwnSignal.SelectedIndex = 0;
            // drpDwnTxNetworkBox.SelectionChanged += drpDwnMailBox_SelectionChanged;
            Grid.SetRow(drpDwnSignal, 2);

            Grid.SetColumn(drpDwnSignal, 1);


            if (lvaluesTx != null && lvaluesTx.Count > 0)
            {
                List<String> lvaluesSignal = new List<String>();
                messagesTxSignal.TryGetValue(lvaluesTx[0].Substring(0, lvaluesTx[0].IndexOf("(")), out lvaluesSignal);
                if (lvaluesSignal != null && lvaluesSignal.Count > 0)
                {
                    selectedSignal = lvaluesSignal[0];
                    drpDwnSignal.ItemsSource = (lvaluesSignal).ToList();
                    drpDwnSignal.SelectionChanged += drpDwnSignal_SelectionChanged;
                }
                else
                {
                    lvaluesSignal = new List<String>();
                    drpDwnSignal.ItemsSource = (lvaluesSignal).ToList();
                    selectedSignal = "";
                }


            }
            else
            {
                List<String> lvaluesSignal = new List<String>();
                drpDwnSignal.ItemsSource = (lvaluesSignal).ToList();
                selectedSignal = "";
            }


            DynamicGrid.Children.Add(drpDwnSignal);




            RowDefinition gridIntital = new RowDefinition();
            gridIntital.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridIntital);


            TextBlock lblInitial = new TextBlock();
            lblInitial.Text = "Initial Value";
            lblInitial.Name = "Range" + "_LbL";
            lblInitial.FontFamily = new FontFamily("Calibri");
            lblInitial.FontSize = 14;
            lblInitial.VerticalAlignment = VerticalAlignment.Center;
            lblInitial.TextWrapping = TextWrapping.Wrap;
            lblInitial.ToolTip = "Initial value of TX signals".Trim();
            Grid.SetRow(lblInitial, 3);
            Grid.SetColumn(lblInitial, 0);

            DynamicGrid.Children.Add(lblInitial);


            TextBox txtBoxInitial = new TextBox();
            txtBoxInitial.Text = "0";
            txtBoxInitial.FontSize = 12;
            txtBoxInitial.FontWeight = FontWeights.Bold;
            txtBoxInitial.Height = 30;
            txtBoxInitial.Background = Brushes.White;
            txtBoxInitial.TextChanged += txtBoxInitial_TextChanged;
            txtBoxInitial.Name = "txtInitial" + "_Val";
            txtBoxInitial.IsEnabled = isManual;


            Grid.SetRow(txtBoxInitial, 3);
            Grid.SetColumn(txtBoxInitial, 1);

            DynamicGrid.Children.Add(txtBoxInitial);



            RowDefinition gridRowCheckBox = new RowDefinition();
            gridRowCheckBox.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowCheckBox);

            TextBlock lblChekBoxText = new TextBlock();
            lblChekBoxText.Text = "Manual configuration";
            lblChekBoxText.Name = "Manual_configuration" + "_Val";
            lblChekBoxText.FontFamily = new FontFamily("Calibri");
            lblChekBoxText.FontSize = 14;
            lblChekBoxText.VerticalAlignment = VerticalAlignment.Center;
            lblChekBoxText.TextWrapping = TextWrapping.Wrap;
            lblChekBoxText.ToolTip = "Check this box to enter initial values for TX signals if unchecked then initial value from DBC will be loaded";

            Grid.SetRow(lblChekBoxText, 4);
            Grid.SetColumn(lblChekBoxText, 0);

            DynamicGrid.Children.Add(lblChekBoxText);

            // Add the Checkbox to enable of disable Manual configuration
            CheckBox chkBoxEnableDisableManualConfiguration = new CheckBox();
            chkBoxEnableDisableManualConfiguration.IsChecked = false;
            chkBoxEnableDisableManualConfiguration.FontSize = 12;
            chkBoxEnableDisableManualConfiguration.FontWeight = FontWeights.Bold;
            chkBoxEnableDisableManualConfiguration.Height = 15;
            chkBoxEnableDisableManualConfiguration.Margin = new Thickness(5, 0, 0, 0);
            chkBoxEnableDisableManualConfiguration.Name = "chkBoxEnableDisableManualConfiguration" + "_Val";
            chkBoxEnableDisableManualConfiguration.Background = Brushes.White;
            chkBoxEnableDisableManualConfiguration.Click += chkBoxEnableDisableManualConfiguration_Clicked;
            Grid.SetRow(chkBoxEnableDisableManualConfiguration, 4);
            Grid.SetColumn(chkBoxEnableDisableManualConfiguration, 1);

            DynamicGrid.Children.Add(chkBoxEnableDisableManualConfiguration);


            // Display grid into a Window
            SpForDynamicGridStaticCan.Children.Add(DynamicGrid);


            RowDefinition gridRowtXNetWorkNode = new RowDefinition();
            gridRowtXNetWorkNode.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowtXNetWorkNode);

            TextBlock lblRxNetworkNode = new TextBlock();
            lblRxNetworkNode.Text = "Rx Messages";
            lblRxNetworkNode.Name = "Rx_Messages" + "_LbL";
            lblRxNetworkNode.FontFamily = new FontFamily("Calibri");
            lblRxNetworkNode.FontSize = 14;
            lblRxNetworkNode.VerticalAlignment = VerticalAlignment.Center;
            lblRxNetworkNode.TextWrapping = TextWrapping.Wrap;
            lblRxNetworkNode.ToolTip = "Rx Messages".Trim();
            Grid.SetRow(lblRxNetworkNode, 5);
            Grid.SetColumn(lblRxNetworkNode, 0);

            DynamicGrid.Children.Add(lblRxNetworkNode);


            ComboBox drpDwnRxNetworkBox = new ComboBox();
            drpDwnRxNetworkBox.Name = "ComboNetworkNodeRx" + "_Val";
            drpDwnRxNetworkBox.FontSize = 12;
            drpDwnRxNetworkBox.FontWeight = FontWeights.Bold;
            drpDwnRxNetworkBox.Height = 30;
            drpDwnRxNetworkBox.Background = Brushes.White;
            drpDwnRxNetworkBox.IsSynchronizedWithCurrentItem = true;
            drpDwnRxNetworkBox.SelectedIndex = 0;

            Grid.SetRow(drpDwnRxNetworkBox, 5);

            Grid.SetColumn(drpDwnRxNetworkBox, 1);



            List<String> lvaluesRx = new List<String>();
            rxMessageWithFrameId.TryGetValue(allNodes[0], out lvaluesRx);
            if (lvaluesRx != null)
            {
                drpDwnRxNetworkBox.ItemsSource = (lvaluesRx).ToList();
                drpDwnRxNetworkBox.SelectionChanged += drpDwnRxNetworkBox_SelectionChanged;
            }
            else
            {
                lvaluesRx = new List<String>();
                drpDwnRxNetworkBox.ItemsSource = (lvaluesRx).ToList();
            }


            DynamicGrid.Children.Add(drpDwnRxNetworkBox);


            if (lvaluesRx != null && lvaluesRx.Count > 0)
            {
                selectedRxMessage = lvaluesRx[0].Substring(0, lvaluesRx[0].IndexOf("("));
            }
            else
            {
                selectedRxMessage = "";
            }





            RowDefinition gridRowReceptionTime = new RowDefinition();
            gridRowReceptionTime.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowReceptionTime);


            TextBlock lblReceptionTime = new TextBlock();
            lblReceptionTime.Text = "Reception Timeout";
            lblReceptionTime.Name = "ReceptionTime" + "_LbL";
            lblReceptionTime.FontFamily = new FontFamily("Calibri");
            lblReceptionTime.FontSize = 14;
            lblReceptionTime.VerticalAlignment = VerticalAlignment.Center;
            lblReceptionTime.TextWrapping = TextWrapping.Wrap;
            lblReceptionTime.ToolTip = "Reception Timeout".Trim();
            Grid.SetRow(lblReceptionTime, 6);
            Grid.SetColumn(lblReceptionTime, 0);

            DynamicGrid.Children.Add(lblReceptionTime);


            TextBox txtBoxReceptionTime = new TextBox();
            txtBoxReceptionTime.Text = "0";
            txtBoxReceptionTime.FontSize = 12;
            txtBoxReceptionTime.FontWeight = FontWeights.Bold;
            txtBoxReceptionTime.Height = 30;
            txtBoxReceptionTime.Background = Brushes.White;
            txtBoxReceptionTime.TextChanged += txtBoxReceptionTime_TextChanged;
            txtBoxReceptionTime.Name = "txtReceptionTime" + "_Val";
            txtBoxReceptionTime.IsEnabled = true;
            Grid.SetRow(txtBoxReceptionTime, 6);
            Grid.SetColumn(txtBoxReceptionTime, 1);

            DynamicGrid.Children.Add(txtBoxReceptionTime);



            RowDefinition gridRowSignalRx = new RowDefinition();
            gridRowSignalRx.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowSignalRx);

            TextBlock lblSignalRx = new TextBlock();
            lblSignalRx.Text = "RX Signals";
            lblSignalRx.Name = "Signal" + "_LbL";
            lblSignalRx.FontFamily = new FontFamily("Calibri");
            lblSignalRx.FontSize = 14;
            lblSignalRx.VerticalAlignment = VerticalAlignment.Center;
            lblSignalRx.TextWrapping = TextWrapping.Wrap;
            lblSignalRx.ToolTip = "RX Signals".Trim();
            Grid.SetRow(lblSignalRx, 7);
            Grid.SetColumn(lblSignalRx, 0);

            DynamicGrid.Children.Add(lblSignalRx);


            ComboBox drpDwnSignalRx = new ComboBox();
            drpDwnSignalRx.Name = "ComboSignalRx" + "_Val";
            drpDwnSignalRx.FontSize = 12;
            drpDwnSignalRx.FontWeight = FontWeights.Bold;
            drpDwnSignalRx.Height = 30;
            drpDwnSignalRx.Background = Brushes.White;
            drpDwnSignalRx.IsSynchronizedWithCurrentItem = true;
            drpDwnSignalRx.SelectedIndex = 0;
            // drpDwnTxNetworkBox.SelectionChanged += drpDwnMailBox_SelectionChanged;
            Grid.SetRow(drpDwnSignalRx, 7);

            Grid.SetColumn(drpDwnSignalRx, 1);


            if (lvaluesRx != null && lvaluesRx.Count > 0)
            {
                List<String> lvaluesSignalRx = new List<String>();
                messagesRxSignal.TryGetValue(lvaluesRx[0].Substring(0, lvaluesRx[0].IndexOf("(")), out lvaluesSignalRx);
                if (lvaluesSignalRx != null && lvaluesSignalRx.Count > 0)
                {
                    selectedSignalRx = lvaluesSignalRx[0];
                    drpDwnSignalRx.ItemsSource = (lvaluesSignalRx).ToList();
                    drpDwnSignalRx.SelectionChanged += drpDwnSignalRx_SelectionChanged;
                }
                else
                {
                    lvaluesSignalRx = new List<String>();
                    drpDwnSignalRx.ItemsSource = (lvaluesSignalRx).ToList();
                    selectedSignalRx = "";
                }


            }
            else
            {
                List<String> lvaluesSignalRx = new List<String>();
                drpDwnSignal.ItemsSource = (lvaluesSignalRx).ToList();
                selectedSignalRx = "";
            }


            DynamicGrid.Children.Add(drpDwnSignalRx);


            RowDefinition gridRowRxCallbackFunction = new RowDefinition();
            gridRowReceptionTime.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowRxCallbackFunction);


            TextBlock lblRxCallbackFunction = new TextBlock();
            lblRxCallbackFunction.Text = "RX Callback Function ";
            lblRxCallbackFunction.Name = "RX_Call_Back_Function" + "_LbL";
            lblRxCallbackFunction.FontFamily = new FontFamily("Calibri");
            lblRxCallbackFunction.FontSize = 14;
            lblRxCallbackFunction.VerticalAlignment = VerticalAlignment.Center;
            lblRxCallbackFunction.TextWrapping = TextWrapping.Wrap;
            lblRxCallbackFunction.ToolTip = "The mapped function shall be invoked on data reception".Trim();
            Grid.SetRow(lblRxCallbackFunction, 8);
            Grid.SetColumn(lblRxCallbackFunction, 0);

            DynamicGrid.Children.Add(lblRxCallbackFunction);


            TextBox txtBoxRxCallbackFunction = new TextBox();
            txtBoxRxCallbackFunction.Text = "0";
            txtBoxRxCallbackFunction.FontSize = 12;
            txtBoxRxCallbackFunction.FontWeight = FontWeights.Bold;
            txtBoxRxCallbackFunction.Height = 30;
            txtBoxRxCallbackFunction.Background = Brushes.White;
            txtBoxRxCallbackFunction.TextChanged += txtBoxRxCallbackFunction_TextChanged;
            txtBoxRxCallbackFunction.Name = "txtCallBack" + "_Val";
            txtBoxRxCallbackFunction.IsEnabled = true;
            Grid.SetRow(txtBoxRxCallbackFunction, 8);
            Grid.SetColumn(txtBoxRxCallbackFunction, 1);

            DynamicGrid.Children.Add(txtBoxRxCallbackFunction);

            RowDefinition gridRowRxCallbackFunctionout = new RowDefinition();
            gridRowRxCallbackFunctionout.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowRxCallbackFunctionout);


            TextBlock lblRxCallbackFunctionOut = new TextBlock();
            lblRxCallbackFunctionOut.Text = "Reception Timeout Callback Function";
            lblRxCallbackFunctionOut.Name = "RX_Call_Back_Function_time_out" + "_LbL";
            lblRxCallbackFunctionOut.FontFamily = new FontFamily("Calibri");
            lblRxCallbackFunctionOut.FontSize = 14;
            lblRxCallbackFunctionOut.VerticalAlignment = VerticalAlignment.Center;
            lblRxCallbackFunctionOut.TextWrapping = TextWrapping.Wrap;
            lblRxCallbackFunctionOut.ToolTip = "The mapped function shall be invoked on reception timeout".Trim();
            Grid.SetRow(lblRxCallbackFunctionOut, 9);
            Grid.SetColumn(lblRxCallbackFunctionOut, 0);

            DynamicGrid.Children.Add(lblRxCallbackFunctionOut);


            TextBox txtBoxRxCallbackFunctionOut = new TextBox();
            txtBoxRxCallbackFunctionOut.Text = "0";
            txtBoxRxCallbackFunctionOut.FontSize = 12;
            txtBoxRxCallbackFunctionOut.FontWeight = FontWeights.Bold;
            txtBoxRxCallbackFunctionOut.Height = 30;
            txtBoxRxCallbackFunctionOut.Background = Brushes.White;
            txtBoxRxCallbackFunctionOut.TextChanged += txtBoxRxCallbackFunctionOut_TextChanged;
            txtBoxRxCallbackFunctionOut.Name = "txtReceptionTimeout" + "_Val";
            txtBoxRxCallbackFunctionOut.IsEnabled = true;
            Grid.SetRow(txtBoxRxCallbackFunctionOut, 9);
            Grid.SetColumn(txtBoxRxCallbackFunctionOut, 1);

            DynamicGrid.Children.Add(txtBoxRxCallbackFunctionOut);




            RowDefinition gridRowAPPLICATION_WAKEUP_CBK = new RowDefinition();
            gridRowAPPLICATION_WAKEUP_CBK.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowAPPLICATION_WAKEUP_CBK);


            TextBlock lblAPPLICATION_WAKEUP_CBK = new TextBlock();
            lblAPPLICATION_WAKEUP_CBK.Text = "Remote Wakeup Callback Function";
            lblAPPLICATION_WAKEUP_CBK.Name = "APPLICATION_WAKEUP_CBK" + "_LbL";
            lblAPPLICATION_WAKEUP_CBK.FontFamily = new FontFamily("Calibri");
            lblAPPLICATION_WAKEUP_CBK.FontSize = 14;
            lblAPPLICATION_WAKEUP_CBK.VerticalAlignment = VerticalAlignment.Center;
            lblAPPLICATION_WAKEUP_CBK.TextWrapping = TextWrapping.Wrap;
            lblAPPLICATION_WAKEUP_CBK.ToolTip = "The mapped function shall be invoked on remote wakeup".Trim();
            Grid.SetRow(lblAPPLICATION_WAKEUP_CBK, 10);
            Grid.SetColumn(lblAPPLICATION_WAKEUP_CBK, 0);

            DynamicGrid.Children.Add(lblAPPLICATION_WAKEUP_CBK);


            TextBox txtBoxAPPLICATION_WAKEUP_CBK = new TextBox();
            txtBoxAPPLICATION_WAKEUP_CBK.Text = "";
            txtBoxAPPLICATION_WAKEUP_CBK.FontSize = 12;
            txtBoxAPPLICATION_WAKEUP_CBK.FontWeight = FontWeights.Bold;
            txtBoxAPPLICATION_WAKEUP_CBK.Height = 30;
            txtBoxAPPLICATION_WAKEUP_CBK.Background = Brushes.White;
            txtBoxAPPLICATION_WAKEUP_CBK.TextChanged += txtBoxAPPLICATION_WAKEUP_CBK_TextChanged;
            txtBoxAPPLICATION_WAKEUP_CBK.Name = "txtReceptionTimeout" + "_Val";
            txtBoxAPPLICATION_WAKEUP_CBK.IsEnabled = true;
            Grid.SetRow(txtBoxAPPLICATION_WAKEUP_CBK, 10);
            Grid.SetColumn(txtBoxAPPLICATION_WAKEUP_CBK, 1);

            DynamicGrid.Children.Add(txtBoxAPPLICATION_WAKEUP_CBK);
            if (APPLICATION_WAKEUP_CBK != null)
            {
                txtBoxAPPLICATION_WAKEUP_CBK.Text = APPLICATION_WAKEUP_CBK;
            }




            RowDefinition gridRowAPPLICATION_NETWORK_REQUEST_CBK_FUNC = new RowDefinition();
            gridRowAPPLICATION_NETWORK_REQUEST_CBK_FUNC.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowAPPLICATION_NETWORK_REQUEST_CBK_FUNC);


            TextBlock lblAPPLICATION_NETWORK_REQUEST_CBK_FUNC = new TextBlock();
            lblAPPLICATION_NETWORK_REQUEST_CBK_FUNC.Text = "Network Request Confirmation Callback Function";
            lblAPPLICATION_NETWORK_REQUEST_CBK_FUNC.Name = "APPLICATION_NETWORK_REQUEST_CBK_FUNC" + "_LbL";
            lblAPPLICATION_NETWORK_REQUEST_CBK_FUNC.FontFamily = new FontFamily("Calibri");
            lblAPPLICATION_NETWORK_REQUEST_CBK_FUNC.FontSize = 14;
            lblAPPLICATION_NETWORK_REQUEST_CBK_FUNC.VerticalAlignment = VerticalAlignment.Center;
            lblAPPLICATION_NETWORK_REQUEST_CBK_FUNC.TextWrapping = TextWrapping.Wrap;
            lblAPPLICATION_NETWORK_REQUEST_CBK_FUNC.ToolTip = "The mapped function shall be invoked on  Network Request Confirmation".Trim();
            Grid.SetRow(lblAPPLICATION_NETWORK_REQUEST_CBK_FUNC, 11);
            Grid.SetColumn(lblAPPLICATION_NETWORK_REQUEST_CBK_FUNC, 0);

            DynamicGrid.Children.Add(lblAPPLICATION_NETWORK_REQUEST_CBK_FUNC);


            TextBox txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC = new TextBox();
            txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC.Text = "";
            txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC.FontSize = 12;
            txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC.FontWeight = FontWeights.Bold;
            txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC.Height = 30;
            txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC.Background = Brushes.White;
            txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC.TextChanged += txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC_TextChanged;
            txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC.Name = "txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC" + "_Val";
            txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC.IsEnabled = true;
            Grid.SetRow(txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC, 11);
            Grid.SetColumn(txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC, 1);
            if (APPLICATION_NETWORK_REQUEST_CBK_FUNC != null)
            {
                txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC.Text = APPLICATION_NETWORK_REQUEST_CBK_FUNC;
            }

            DynamicGrid.Children.Add(txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC);




            RowDefinition gridRowAPPLICATION_BUSOFF_INDICATION = new RowDefinition();
            gridRowAPPLICATION_BUSOFF_INDICATION.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowAPPLICATION_BUSOFF_INDICATION);


            TextBlock lblAPPLICATION_BUSOFF_INDICATION = new TextBlock();
            lblAPPLICATION_BUSOFF_INDICATION.Text = "BusOFF Indication";
            lblAPPLICATION_BUSOFF_INDICATION.Name = "APPLICATION_BUSOFF_INDICATION" + "_LbL";
            lblAPPLICATION_BUSOFF_INDICATION.FontFamily = new FontFamily("Calibri");
            lblAPPLICATION_BUSOFF_INDICATION.FontSize = 14;
            lblAPPLICATION_BUSOFF_INDICATION.VerticalAlignment = VerticalAlignment.Center;
            lblAPPLICATION_BUSOFF_INDICATION.TextWrapping = TextWrapping.Wrap;
            lblAPPLICATION_BUSOFF_INDICATION.ToolTip = "The mapped function shall be invoked on CAN bus off condition".Trim();
            Grid.SetRow(lblAPPLICATION_BUSOFF_INDICATION, 12);
            Grid.SetColumn(lblAPPLICATION_BUSOFF_INDICATION, 0);

            DynamicGrid.Children.Add(lblAPPLICATION_BUSOFF_INDICATION);


            TextBox txtBoxAPPLICATION_BUSOFF_INDICATION = new TextBox();
            txtBoxAPPLICATION_BUSOFF_INDICATION.Text = "";
            txtBoxAPPLICATION_BUSOFF_INDICATION.FontSize = 12;
            txtBoxAPPLICATION_BUSOFF_INDICATION.FontWeight = FontWeights.Bold;
            txtBoxAPPLICATION_BUSOFF_INDICATION.Height = 30;
            txtBoxAPPLICATION_BUSOFF_INDICATION.Background = Brushes.White;
            txtBoxAPPLICATION_BUSOFF_INDICATION.TextChanged += txtBoxAPPLICATION_BUSOFF_INDICATION_TextChanged;
            txtBoxAPPLICATION_BUSOFF_INDICATION.Name = "txtBoxAPPLICATION_BUSOFF_INDICATION" + "_Val";
            txtBoxAPPLICATION_BUSOFF_INDICATION.IsEnabled = true;
            Grid.SetRow(txtBoxAPPLICATION_BUSOFF_INDICATION, 12);
            Grid.SetColumn(txtBoxAPPLICATION_BUSOFF_INDICATION, 1);

            DynamicGrid.Children.Add(txtBoxAPPLICATION_BUSOFF_INDICATION);
            if (APPLICATION_BUSOFF_INDICATION != null)
            {
                txtBoxAPPLICATION_BUSOFF_INDICATION.Text = APPLICATION_BUSOFF_INDICATION;
            }




            RowDefinition gridRowMAINFUNCTION_PERIOD = new RowDefinition();
            gridRowMAINFUNCTION_PERIOD.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowMAINFUNCTION_PERIOD);


            TextBlock lblMAINFUNCTION_PERIOD = new TextBlock();
            lblMAINFUNCTION_PERIOD.Text = "Mainfunction Periodicity";
            lblMAINFUNCTION_PERIOD.Name = "MAINFUNCTION_PERIOD" + "_LbL";
            lblMAINFUNCTION_PERIOD.FontFamily = new FontFamily("Calibri");
            lblMAINFUNCTION_PERIOD.FontSize = 14;
            lblMAINFUNCTION_PERIOD.VerticalAlignment = VerticalAlignment.Center;
            lblMAINFUNCTION_PERIOD.TextWrapping = TextWrapping.Wrap;
            lblMAINFUNCTION_PERIOD.ToolTip = "Periodicity of CAN Manager Mainfunction".Trim();
            Grid.SetRow(lblMAINFUNCTION_PERIOD, 13);
            Grid.SetColumn(lblMAINFUNCTION_PERIOD, 0);

            DynamicGrid.Children.Add(lblMAINFUNCTION_PERIOD);


            TextBox txtBoxMAINFUNCTION_PERIOD = new TextBox();
            txtBoxMAINFUNCTION_PERIOD.Text = "";
            txtBoxMAINFUNCTION_PERIOD.FontSize = 12;
            txtBoxMAINFUNCTION_PERIOD.FontWeight = FontWeights.Bold;
            txtBoxMAINFUNCTION_PERIOD.Height = 30;
            txtBoxMAINFUNCTION_PERIOD.Background = Brushes.White;
            txtBoxMAINFUNCTION_PERIOD.TextChanged += txtBoxMAINFUNCTION_PERIOD_TextChanged;
            txtBoxMAINFUNCTION_PERIOD.Name = "txtBoxMAINFUNCTION_PERIOD" + "_Val";
            txtBoxMAINFUNCTION_PERIOD.IsEnabled = true;
            Grid.SetRow(txtBoxMAINFUNCTION_PERIOD, 13);
            Grid.SetColumn(txtBoxMAINFUNCTION_PERIOD, 1);

            DynamicGrid.Children.Add(txtBoxMAINFUNCTION_PERIOD);
            if (MAINFUNCTION_PERIOD != null)
            {
                txtBoxMAINFUNCTION_PERIOD.Text = MAINFUNCTION_PERIOD;
            }


            RowDefinition gridRowAddHeader = new RowDefinition();
            gridRowAddHeader.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowAddHeader);


            TextBlock lblHeader = new TextBlock();
            lblHeader.Text = "Includes";
            lblHeader.Name = "Header" + "_LbL";
            lblHeader.FontFamily = new FontFamily("Calibri");
            lblHeader.FontSize = 14;
            lblHeader.VerticalAlignment = VerticalAlignment.Center;
            lblHeader.TextWrapping = TextWrapping.Wrap;
            lblHeader.ToolTip = "Include Files".Trim();
            Grid.SetRow(lblHeader, 14);
            Grid.SetColumn(lblHeader, 0);

            DynamicGrid.Children.Add(lblHeader);


            TextBox txtBoxHeader = new TextBox();
            txtBoxHeader.Text = "";
            txtBoxHeader.FontSize = 12;
            txtBoxHeader.FontWeight = FontWeights.Bold;
            txtBoxHeader.Height = 30;
            txtBoxHeader.Background = Brushes.White;

            txtBoxHeader.Name = "txtBoxHeader" + "_Val";
            txtBoxHeader.IsEnabled = true;
            Grid.SetRow(txtBoxHeader, 14);
            Grid.SetColumn(txtBoxHeader, 1);

            DynamicGrid.Children.Add(txtBoxHeader);
            RowDefinition gridRowAddHeaders = new RowDefinition();
            gridRowAddHeaders.Height = new GridLength(45);
            DynamicGrid.RowDefinitions.Add(gridRowAddHeaders);
            Button btnAddSubmit = new Button();
            btnAddSubmit.IsEnabled = true;
            btnAddSubmit.Width = 135;
            btnAddSubmit.Content = "Add Header Directive";
            btnAddSubmit.Name = "btnAddSubmit" + "_Val";
            btnAddSubmit.FontSize = 12;
            btnAddSubmit.FontWeight = FontWeights.Bold;
            btnAddSubmit.Height = 30;
            btnAddSubmit.Click += btnAddSubmitHeader_Clicked;
            Grid.SetRow(btnAddSubmit, 14);
            Grid.SetColumn(btnAddSubmit, 2);

            DynamicGrid.Children.Add(btnAddSubmit);
            if (allObjects != null)
            {
                try
                {
                    drpDwnNetworkBox.SelectedIndex = 1;
                    drpDwnNetworkBox.SelectedIndex = 0;
                    drpDwnNetworkBox.SelectedIndex = allNodes.IndexOf(snode);
                    drpDwnNetworkBox_SelectionChanged(drpDwnNetworkBox, null);
                }
                catch (Exception e)
                {
                    Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                }
            }

            RowDefinition gridRowShowHeaders = new RowDefinition();
            gridRowShowHeaders.Height = new GridLength(100);
            DynamicGrid.RowDefinitions.Add(gridRowShowHeaders);

            var panelTemplateHeaders = new ItemsPanelTemplate();
            var stackPanelHeaders = new FrameworkElementFactory(typeof(StackPanel));
            stackPanelHeaders.SetValue(StackPanel.OrientationProperty, Orientation.Vertical);
            panelTemplateHeaders.VisualTree = stackPanelHeaders;

            ListBox listBoxHeader = new ListBox();
            listBoxHeader.ItemsPanel = panelTemplateHeaders;


            listBoxHeader.SetValue(Grid.RowProperty, 0);
            listBoxHeader.SetValue(Grid.ColumnProperty, 0);
            listBoxHeader.FontFamily = new FontFamily("Verdana");
            listBoxHeader.FontSize = 12;

            listBoxHeader.FontWeight = FontWeights.Bold;
            listBoxHeader.Background = Brushes.White;
            Grid.SetRow(listBoxHeader, 15);
            Grid.SetColumn(listBoxHeader, 1);

            if (headerFils != null)
            {
                foreach (String hd in headerFils)
                {
                    listBoxHeader.Items.Add(hd);
                }
            }


            DynamicGrid.Children.Add(listBoxHeader);

            Button btnAddRemoveHeader = new Button();
            btnAddRemoveHeader.IsEnabled = true;
            btnAddRemoveHeader.Width = 135;
            btnAddRemoveHeader.Content = "Remove Header";
            btnAddRemoveHeader.Name = "btnAddRemove" + "_Val";
            btnAddRemoveHeader.FontSize = 12;
            btnAddRemoveHeader.FontWeight = FontWeights.Bold;
            btnAddRemoveHeader.Height = 30;
            btnAddRemoveHeader.Click += btnRemoveSubmitHederM_Clicked;
            Grid.SetRow(btnAddRemoveHeader, 15);
            Grid.SetColumn(btnAddRemoveHeader, 2);
           
            DynamicGrid.Children.Add(btnAddRemoveHeader);

            try
            {
                File.Delete(DockingManagerModelHelper.TargetOutputFolderPath + "\\" + fileName + ".txt");
            }
            catch (Exception e) { Logger.Log.Instance.Error("Exception encountered with message: " + e.Message); }

            try
            {
                File.Delete(DockingManagerModelHelper.TargetOutputFolderPath + "\\" + "decode" + ".txt");
            }
            catch (Exception e) { Logger.Log.Instance.Error("Exception encountered with message: " + e.Message); }
            try
            {
                File.Delete(DockingManagerModelHelper.TargetOutputFolderPath + "\\" + "encode" + ".txt");
            }
            catch (Exception e) { Logger.Log.Instance.Error("Exception encountered with message: " + e.Message); }
            try
            {
                File.Delete(DockingManagerModelHelper.TargetOutputFolderPath + "\\" + "pack" + ".txt");
            }
            catch (Exception e) { Logger.Log.Instance.Error("Exception encountered with message: " + e.Message); }
            try
            {
                File.Delete(DockingManagerModelHelper.TargetOutputFolderPath + "\\" + "static" + ".txt");
            }
            catch (Exception e) { Logger.Log.Instance.Error("Exception encountered with message: " + e.Message); }
            try
            {
                File.Delete(DockingManagerModelHelper.TargetOutputFolderPath + "\\" + "unpack" + ".txt");
            }
            catch (Exception e) { Logger.Log.Instance.Error("Exception encountered with message: " + e.Message); }
            try
            {
                File.Delete(DockingManagerModelHelper.TargetOutputFolderPath + "\\" + "range" + ".txt");
            }
            catch (Exception e) { Logger.Log.Instance.Error("Exception encountered with message: " + e.Message); }

            try
            {
                File.Delete(DockingManagerModelHelper.TargetOutputFolderPath + "\\" + fnamec + ".c");
            }
            catch (Exception e) { Logger.Log.Instance.Error("Exception encountered with message: " + e.Message); }

            try
            {
                File.Delete(DockingManagerModelHelper.TargetOutputFolderPath + "\\" + fnamec + ".h");
            }
            catch (Exception e) { Logger.Log.Instance.Error("Exception encountered with message: " + e.Message); }


        }

        private void ChkBox_Click(object sender, RoutedEventArgs e)
        {
            var cb = sender as CheckBox;
            var grd = SpForDynamicGrid.Children.OfType<Grid>().FirstOrDefault();

            if (grd != null)
            {
                var currSelectedMailBox = grd.Children
                                            .OfType<ComboBox>()
                                            .Where(cbx => cbx.Name == "CAN_DRIVER_MAILBOX_INTERRUPT_PRIORITY_Val")
                                            .FirstOrDefault();
                var c4 = currSelectedMailBox as System.Windows.Controls.ComboBox;
                c4.IsEnabled = (bool)cb.IsChecked;
            }

        }
        private void chkBoxEnableDisableManualConfiguration_Clicked(object sender, RoutedEventArgs e)
        {
            var cb = sender as CheckBox;
            isManual = (bool)cb.IsChecked;
            var textBoxRange = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[0];
            textBoxRange.IsEnabled = isManual;
        }

        private void MailboxCtrl_Clicked(object sender, RoutedEventArgs e)
        {
            var cb = sender as CheckBox;

            var grd = SpForDynamicGrid.Children.OfType<Grid>().FirstOrDefault();

            if (grd != null)
            {
                var currSelectedMailBox = grd.Children
                                            .OfType<ComboBox>()
                                            .Where(cbx => cbx.Name == cb.Name.ToString())
                                            .FirstOrDefault();
                if (currSelectedMailBox != null)
                {
                    var currSelectedMailBoxCB = grd.Children
                                                .OfType<CheckBox>()
                                                .Where(cbx => cbx.Name == currSelectedMailBox.Name.ToString())
                                                .FirstOrDefault();

                    if (currSelectedMailBoxCB != null)
                    {
                        var a1 = DockingManagerModelHelper.Configuration.ARPACKAGES.Where(a => a.SHORTNAME == DockingManagerModelHelper.ModuleName).FirstOrDefault();
                        var a2 = a1.ELEMENTS.ECUCMODULECONFIGURATIONVALUES.CONTAINERS.SUBCONTAINERS.Where(b => b.SUBCONTAINERS.Length > 1).FirstOrDefault();
                        var currentConfigParamChild = a2.SUBCONTAINERS.Where(c => c.SHORTNAME.Equals(currSelectedMailBox.SelectedValue.ToString(), StringComparison.OrdinalIgnoreCase)).FirstOrDefault();

                        // Update the user input value back to the object
                        currentConfigParamChild.PARAMETERVALUES.VALUE.Value = (bool)cb.IsChecked ? "ENABLE" : "DISABLE";

                        //Below loop will is used to change enable/disable the child controls.
                        foreach (var child in grd.Children)
                        {
                            switch (child.GetType().Name.ToLower())
                            {
                                case "textbox":
                                    var c2 = child as System.Windows.Controls.TextBox;
                                    string str = currentConfigParamChild.SUBCONTAINERS.Where(a => a.PARAMETERVALUES.DEFINITIONREF.name.Equals(c2.Name.Substring(0, c2.Name.IndexOf("_Val")), StringComparison.OrdinalIgnoreCase)).Select(a => a.PARAMETERVALUES.DEFINITIONREF.name).FirstOrDefault();
                                    if (c2.Name.Equals(str + "_Val", StringComparison.OrdinalIgnoreCase))
                                    {
                                        c2.IsEnabled = (bool)cb.IsChecked;
                                    }
                                    break;
                                case "checkbox":
                                    var c3 = child as System.Windows.Controls.CheckBox;
                                    string strCB = currentConfigParamChild.SUBCONTAINERS.Where(a => a.PARAMETERVALUES.DEFINITIONREF.name.Equals(c3.Name.Substring(0, c3.Name.IndexOf("_Val")), StringComparison.OrdinalIgnoreCase)).Select(a => a.PARAMETERVALUES.DEFINITIONREF.name).FirstOrDefault();
                                    if (c3.Name.Equals(strCB + "_Val", StringComparison.OrdinalIgnoreCase))
                                    {
                                        c3.IsEnabled = (bool)cb.IsChecked;
                                    }
                                    break;
                                case "combobox":
                                    var c4 = child as System.Windows.Controls.ComboBox;
                                    string strCmb = currentConfigParamChild.SUBCONTAINERS.Where(a => a.PARAMETERVALUES.DEFINITIONREF.name.Equals(c4.Name.Substring(0, c4.Name.IndexOf("_Val")), StringComparison.OrdinalIgnoreCase)).Select(a => a.PARAMETERVALUES.DEFINITIONREF.name).FirstOrDefault();
                                    if (c4.Name.Equals(strCmb + "_Val", StringComparison.OrdinalIgnoreCase))
                                    {
                                        c4.IsEnabled = (bool)cb.IsChecked;
                                    }
                                    break;
                            }
                        }
                    }
                }
            }
        }

        private void TxtBox_LostFocus(object sender, RoutedEventArgs e)
        {
            var tb = sender as TextBox;

            var tempParamName = tb.Name.Remove(tb.Name.Length - 4);

            var obj = RetrieveConfigParamObject(tempParamName);

            string MinimumValue = obj.PARAMETERVALUES.SUPPORTEDVALUES.MinValue.ToString();
            string MaximumValue = obj.PARAMETERVALUES.SUPPORTEDVALUES.MaxValue.ToString();

            uint userInput;
            bool parseSuccess = uint.TryParse(tb.Text, System.Globalization.NumberStyles.HexNumber, null, out userInput);

            uint minvalue;
            parseSuccess = uint.TryParse(obj.PARAMETERVALUES.SUPPORTEDVALUES.MinValue.ToString(), System.Globalization.NumberStyles.HexNumber, null, out minvalue);

            uint maxvalue;
            parseSuccess = uint.TryParse(obj.PARAMETERVALUES.SUPPORTEDVALUES.MaxValue.ToString(), System.Globalization.NumberStyles.HexNumber, null, out maxvalue);

            if ((userInput < minvalue) || (userInput > maxvalue))
            {
                // Validation failed, Throw erro msg and take the focus back to the textbox
                MessageBox.Show(String.Format("Entered value of {0} should be between {1} and {2}, both values included", obj.PARAMETERVALUES.DEFINITIONREF.name, MinimumValue, MaximumValue));
                tb.Text = obj.PARAMETERVALUES.VALUE.Value.ToString();
            }
        }

        private void listBoxTxFrameId_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var lb = (sender as ListBox);
            ComboBox selectedListBoxLxFrameId = (ComboBox)lb.SelectedItem;
            if (selectedListBoxLxFrameId != null)
            {
                var listBoxFrame = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[1];
                listBoxFrame.SelectedIndex = lb.SelectedIndex;
                var listBoxMaskValue = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[2];
                listBoxMaskValue.SelectedIndex = lb.SelectedIndex;

            }
        }


        private void listBoxMaskValue_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var lb = (sender as ListBox);
            TextBox selectedListBoxTx = (TextBox)lb.SelectedItem;
            if (selectedListBoxTx != null)
            {
                var listBoxFrameId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[0];
                listBoxFrameId.SelectedIndex = lb.SelectedIndex;
                var listBoxFrameMsg = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[1];
                listBoxFrameMsg.SelectedIndex = lb.SelectedIndex;
            }
        }
        private void listBoxTx_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var lb = (sender as ListBox);
            ComboBox selectedListBoxTx = (ComboBox)lb.SelectedItem;
            if (selectedListBoxTx != null)
            {
                var listBoxFrameId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[0];
                listBoxFrameId.SelectedIndex = lb.SelectedIndex;
                var listBoxMaskValue = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[2];
                listBoxMaskValue.SelectedIndex = lb.SelectedIndex;
            }
        }

        private void drpDwnMailRxBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var dd = (sender as ComboBox);
            string selectedMailRx = (string)dd.SelectedItem;
            if (selectedMailRx != null && !selectedMailRx.Trim().Equals(""))
            {
                selectMailBoxMessageRx = selectedMailRx;
                var drMailRxFrameIdBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[4];
                drMailRxFrameIdBox.SelectedIndex = dd.SelectedIndex;
                selectMailBoxFrameIdRx = (string)dd.SelectedItem;
                var txtBocxDlcRx = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[2];
                if (messagesRxDLC.ContainsKey(selectedMailRx))
                {
                    txtBocxDlcRx.Text = messagesTxDLC[selectedMailRx];
                }


            }



        }
        private void drpDwnMailTxBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var dd = (sender as ComboBox);
            string selectedMailTx = (string)dd.SelectedItem;
            if (selectedMailTx != null && !selectedMailTx.Trim().Equals(""))
            {
                selectMailBoxMessage = selectedMailTx;

                var drMailTxFrameIdBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[3];
                drMailTxFrameIdBox.SelectedIndex = dd.SelectedIndex;
                var drMailCanIf = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[1];
                string canifMailBox = (string)drMailCanIf.SelectedItem;
                if (canifMailBox != null)
                {
                    var txtDLC = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[0];
                    if (canifMailBox.Equals("CANIF_TxBasicCANMailbox") || canifMailBox.Equals("CANIF_TxFullCANMailbox"))
                    {
                        txtDLC.Text = messagesTxDLC.ContainsKey(selectMailBoxMessage) ? messagesTxDLC[selectMailBoxMessage] : "0";
                    }
                    else if (canifMailBox.Equals("CANIF_RxBasicCANMailbox") || canifMailBox.Equals("CANIF_RxFullCANMailbox"))
                    {
                        txtDLC.Text = messagesRxDLC.ContainsKey(selectMailBoxMessage) ? messagesRxDLC[selectMailBoxMessage] : "0";
                    }
                }


            }



        }

        private void drpDwnMailRxFrameIdBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

            var dd = (sender as ComboBox);
            string selectedMailrxFrameId = (string)dd.SelectedItem;
            if (selectedMailrxFrameId != null)
            {
                selectMailBoxFrameIdRx = selectedMailrxFrameId;
                var drMailRx = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[5];
                drMailRx.SelectedIndex = dd.SelectedIndex;
                var txtBocxDlcRx = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[2];
                txtBocxDlcRx.Text = messagesRxDLC.ContainsKey((string)drMailRx.SelectedItem) ? messagesRxDLC[(string)drMailRx.SelectedItem] : "0";
            }



        }


        private void drpDwnMailTxMessageBoxs_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

            ComboBox dd = (sender as ComboBox);
            object parent = dd.Parent;
            if (parent != null)
            {
                ListBox lb = (ListBox)parent;
                int itemIndex = lb.Items.IndexOf(dd);
                lb.SelectedIndex = itemIndex;

                var listBoxMessageFrameId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[0];

                ComboBox messageFrameId = (ComboBox)listBoxMessageFrameId.Items[itemIndex];
                messageFrameId.SelectedIndex = dd.SelectedIndex;



            }




        }

        private void drpDwnMailTxFrameIdBoxs_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

            ComboBox dd = (sender as ComboBox);
            object parent = dd.Parent;
            if (parent != null)
            {
                ListBox lb = (ListBox)parent;
                int itemIndex = lb.Items.IndexOf(dd);
                lb.SelectedIndex = itemIndex;

                var listBoxMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[1];

                ComboBox message = (ComboBox)listBoxMessage.Items[itemIndex];
                message.SelectedIndex = dd.SelectedIndex;



            }







        }
        private void drpDwnMailTxFrameIdBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

            var dd = (sender as ComboBox);
            string selectedMailTxFrameId = (string)dd.SelectedItem;
            if (selectedMailTxFrameId != null)
            {
                selectMailBoxFrameId = selectedMailTxFrameId;

                var drMailTx = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[4];
                drMailTx.SelectedIndex = dd.SelectedIndex;

            }



        }
        private void drpDwnMailCanIfBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {


            var dd = (sender as ComboBox);
            string mailBoxCanIfType = (string)dd.SelectedItem;
            //start

            try
            {
                if (fnamec != null && !fnamec.Trim().Equals(""))
                {
                    var drMailBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[0];
                    var drMailCanIf = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[1];
                    var drNetworkNode = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[2];
                    var drMailFrameId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[3];
                    var drMailMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[4];

                    var txtDLC = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[0];

                    var txtMaskValue = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[1];
                    var btnAddMore = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<Button>().ToList()[0];
                    var btnSubmit = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<Button>().ToList()[1];
                    var btnRemove = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<Button>().ToList()[2];
                    string canifMailBox = (string)drMailCanIf.SelectedItem;
                    String mailbox = (string)drMailBox.SelectedItem;
                    selectedMailBox = mailbox;
                    var lblTxFrameIdBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBlock>().ToList()[3];
                    var lblTxBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBlock>().ToList()[4];
                    var lblDLCTX = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBlock>().ToList()[5];
                    var lblMaskValueBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBlock>().ToList()[6];

                    var listBoxFrameId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[0];
                    var listBoxMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[1];
                    var listBoxMessageMaskValue = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[2];

                    listBoxFrameId.Items.Clear();
                    listBoxMessage.Items.Clear();
                    listBoxMessageMaskValue.Items.Clear();
                    if (canifMailBox != null)
                    {

                        btnSubmit.IsEnabled = true;
                        drMailFrameId.IsEnabled = true;
                        drMailMessage.IsEnabled = true;
                        txtDLC.IsEnabled = false;
                        txtMaskValue.IsEnabled = true;
                        if (mailBoxCanifNode.ContainsKey(mailbox))
                        {
                            drNetworkNode.SelectedIndex = allNodes.IndexOf(mailBoxCanifNode[mailbox]);
                        }
                        String selectedNode = (string)drNetworkNode.SelectedItem;

                        if (canifMailBox.Equals("CANIF_RxBasicCANMailbox") || canifMailBox.Equals("CANIF_RxFullCANMailbox"))
                        {

                            lblMaskValueBox.Text = "Rx Mask Value";
                            lblMaskValueBox.ToolTip = "Rx Mask Value";
                            lblDLCTX.ToolTip = "Rx DLC";
                            lblDLCTX.Text = "Rx DLC";
                            lblTxBox.Text = "Rx Message";
                            lblTxBox.ToolTip = "Rx Message";
                            lblTxFrameIdBox.ToolTip = "Rx Message Frame Id";
                            lblTxFrameIdBox.Text = "Rx Message FrameId";


                            if (true)
                            {
                                List<string> onlyRxMessageAlloted = new List<string>();
                                List<string> onlyRxMessageFrameIdAlloted = new List<string>();
                                foreach (KeyValuePair<string, string> kvp in mailBoxMessageRx)
                                {
                                    onlyRxMessageAlloted.Add(kvp.Value);
                                    onlyRxMessageFrameIdAlloted.Add(messagesRxFrameIds[kvp.Value]);

                                }
                                foreach (KeyValuePair<string, List<String>> kvp in mailBoxMessageMoreRx)
                                {
                                    List<String> ls = kvp.Value;
                                    if (ls != null)
                                    {
                                        foreach (String s in ls)
                                        {
                                            onlyRxMessageAlloted.Add(s);
                                            onlyRxMessageFrameIdAlloted.Add(messagesRxFrameIds[s]);
                                        }
                                    }

                                }
                                List<string> rxMessagesRemaing = new List<string>();
                                List<string> rxMessagesFrameIdRemaing = new List<string>();
                                List<string> allRxMessagesNode = rxMessage.ContainsKey(selectedNode) ? rxMessage[selectedNode] : null;
                                if (allRxMessagesNode != null && allRxMessagesNode.Count > 0)
                                {
                                    foreach (string message in allRxMessagesNode)
                                    {
                                        if (!onlyRxMessageAlloted.Contains(message))
                                        {
                                            rxMessagesRemaing.Add(message);
                                            rxMessagesFrameIdRemaing.Add(messagesRxFrameIds[message]);
                                        }
                                    }
                                }
                                drMailMessage.ItemsSource = rxMessagesRemaing;
                                drMailFrameId.ItemsSource = rxMessagesFrameIdRemaing;
                                if (mailBoxCanif.ContainsKey(mailbox))
                                {
                                    btnSubmit.Content = "Edit/Update";
                                    btnSubmit.IsEnabled = true;


                                    if (canifMailBox.Equals("CANIF_RxBasicCANMailbox"))
                                    {
                                        //start
                                        btnAddMore.IsEnabled = true;

                                        if (mailBoxMessageMoreRx.ContainsKey(selectedMailBox))
                                        {
                                            List<string> rxMoreMessagesFrameids = mailBoxFrameIdMoreRx[selectedMailBox];
                                            List<string> rxMoreMessages = mailBoxMessageMoreRx[selectedMailBox];
                                            if (rxMoreMessagesFrameids != null && rxMoreMessagesFrameids.Count > 0)
                                            {
                                                btnRemove.IsEnabled = true;
                                                for (int ind = 0; ind < rxMoreMessagesFrameids.Count; ind++)
                                                {

                                                    ComboBox drpDwnMailRxFrameIdBox = new ComboBox();
                                                    drpDwnMailRxFrameIdBox.Name = "MailFrame" + ind + "_Val";
                                                    drpDwnMailRxFrameIdBox.FontSize = 12;
                                                    drpDwnMailRxFrameIdBox.FontWeight = FontWeights.Bold;
                                                    drpDwnMailRxFrameIdBox.Height = 30;
                                                    drpDwnMailRxFrameIdBox.Width = 280;
                                                    drpDwnMailRxFrameIdBox.Background = Brushes.White;
                                                    drpDwnMailRxFrameIdBox.IsSynchronizedWithCurrentItem = true;
                                                    drpDwnMailRxFrameIdBox.SelectionChanged += drpDwnMailTxFrameIdBoxs_SelectionChanged;

                                                    ComboBox drpDwnMailRxMessageBox = new ComboBox();
                                                    drpDwnMailRxMessageBox.Name = "MailMessage" + ind + "_Val";
                                                    drpDwnMailRxMessageBox.FontSize = 12;
                                                    drpDwnMailRxMessageBox.FontWeight = FontWeights.Bold;
                                                    drpDwnMailRxMessageBox.Height = 30;
                                                    drpDwnMailRxMessageBox.Width = 280;
                                                    drpDwnMailRxMessageBox.Background = Brushes.White;
                                                    drpDwnMailRxMessageBox.IsSynchronizedWithCurrentItem = true;
                                                    drpDwnMailRxMessageBox.SelectionChanged += drpDwnMailTxMessageBoxs_SelectionChanged; ;
                                                    List<string> rxMsgsFrameid = new List<string>();
                                                    rxMsgsFrameid.Add(rxMoreMessagesFrameids[ind]);
                                                    List<string> rxMsgs = new List<string>();
                                                    rxMsgs.Add(rxMoreMessages[ind]);
                                                    foreach (string frid in rxMessagesFrameIdRemaing)
                                                    {
                                                        rxMsgsFrameid.Add(frid);
                                                    }
                                                    foreach (string rxm in rxMessagesRemaing)
                                                    {
                                                        rxMsgs.Add(rxm);
                                                    }
                                                    drpDwnMailRxFrameIdBox.ItemsSource = rxMsgsFrameid;
                                                    drpDwnMailRxMessageBox.ItemsSource = rxMsgs;

                                                    TextBox txtBoxMaskValue = new TextBox();
                                                    txtBoxMaskValue.Text = mailBoxMaskValueMoreRx[selectedMailBox][ind];
                                                    txtBoxMaskValue.FontSize = 12;
                                                    txtBoxMaskValue.FontWeight = FontWeights.Bold;
                                                    txtBoxMaskValue.Height = 30;
                                                    txtBoxMaskValue.Background = Brushes.White;
                                                    txtBoxMaskValue.IsEnabled = true;
                                                    txtBoxMaskValue.Width = 280;

                                                    txtBoxMaskValue.Name = "txtMask" + ind + "_Val";

                                                    listBoxFrameId.Items.Add(drpDwnMailRxFrameIdBox);
                                                    listBoxMessage.Items.Add(drpDwnMailRxMessageBox);
                                                    listBoxMessageMaskValue.Items.Add(txtBoxMaskValue);

                                                }

                                            }
                                        }
                                        //end


                                    }

                                    rxMessagesFrameIdRemaing.Insert(0, mailBoxFrameIdRx[mailbox]);
                                    rxMessagesRemaing.Insert(0, mailBoxMessageRx[mailbox]);
                                    drMailMessage.SelectedIndex = 0;
                                    txtDLC.Text = mailBoxDLCRx[mailbox];
                                    txtMaskValue.Text = mailBoxMaskValueRx[mailbox];
                                }



                                txtDLC.Text = messagesRxDLC.ContainsKey((string)drMailMessage.SelectedItem) ? messagesRxDLC[(string)drMailMessage.SelectedItem] : "0";



                            }


                        }
                        else if (canifMailBox.Equals("CANIF_TxBasicCANMailbox") || canifMailBox.Equals("CANIF_TxFullCANMailbox"))
                        {

                            lblMaskValueBox.Text = "Tx Mask Value";
                            lblMaskValueBox.ToolTip = "Tx Mask Value";
                            lblDLCTX.ToolTip = "Tx DLC";
                            lblDLCTX.Text = "Tx DLC";
                            lblTxBox.Text = "Tx Message";
                            lblTxBox.ToolTip = "Tx Message";
                            lblTxFrameIdBox.ToolTip = "Tx Message Frame Id";
                            lblTxFrameIdBox.Text = "Tx Message FrameId";


                            if (true)
                            {
                                List<string> onlyTxMessageAlloted = new List<string>();
                                List<string> onlyTxMessageFrameIdAlloted = new List<string>();
                                foreach (KeyValuePair<string, string> kvp in mailBoxMessage)
                                {
                                    onlyTxMessageAlloted.Add(kvp.Value);
                                    onlyTxMessageFrameIdAlloted.Add(messagesTxFrameIds[kvp.Value]);

                                }
                                foreach (KeyValuePair<string, List<String>> kvp in mailBoxMessageMore)
                                {
                                    List<String> ls = kvp.Value;
                                    if (ls != null)
                                    {
                                        foreach (String s in ls)
                                        {
                                            onlyTxMessageAlloted.Add(s);
                                            onlyTxMessageFrameIdAlloted.Add(messagesTxFrameIds[s]);
                                        }
                                    }

                                }
                                List<string> txMessagesRemaing = new List<string>();
                                List<string> txMessagesFrameIdRemaing = new List<string>();
                                List<string> allTxMessagesNode = txMessage.ContainsKey(selectedNode) ? txMessage[selectedNode] : null;
                                if (allTxMessagesNode != null && allTxMessagesNode.Count > 0)
                                {
                                    foreach (string message in allTxMessagesNode)
                                    {
                                        if (!onlyTxMessageAlloted.Contains(message))
                                        {
                                            txMessagesRemaing.Add(message);
                                            txMessagesFrameIdRemaing.Add(messagesTxFrameIds[message]);
                                        }
                                    }
                                }

                                drMailMessage.ItemsSource = txMessagesRemaing;
                                drMailFrameId.ItemsSource = txMessagesFrameIdRemaing;
                                txtDLC.Text = messagesTxDLC.ContainsKey((string)drMailMessage.SelectedItem) ? messagesTxDLC[(string)drMailMessage.SelectedItem] : "0";
                                //s1
                                if (mailBoxCanif.ContainsKey(mailbox))
                                {
                                    btnSubmit.Content = "Edit/Update";
                                    btnSubmit.IsEnabled = true;

                                    if (canifMailBox.Equals("CANIF_TxBasicCANMailbox"))
                                    {
                                        btnAddMore.IsEnabled = true;
                                        //start

                                        if (mailBoxMessageMore.ContainsKey(selectedMailBox))
                                        {
                                            List<string> txMoreMessagesFrameids = mailBoxFrameIdMore[selectedMailBox];
                                            List<string> txMoreMessages = mailBoxMessageMore[selectedMailBox];
                                            if (txMoreMessagesFrameids != null && txMoreMessagesFrameids.Count > 0)
                                            {
                                                btnRemove.IsEnabled = true;
                                                for (int ind = 0; ind < txMoreMessagesFrameids.Count; ind++)
                                                {

                                                    ComboBox drpDwnMailRxFrameIdBox = new ComboBox();
                                                    drpDwnMailRxFrameIdBox.Name = "MailFrame" + ind + "_Val";
                                                    drpDwnMailRxFrameIdBox.FontSize = 12;
                                                    drpDwnMailRxFrameIdBox.FontWeight = FontWeights.Bold;
                                                    drpDwnMailRxFrameIdBox.Height = 30;
                                                    drpDwnMailRxFrameIdBox.Width = 280;
                                                    drpDwnMailRxFrameIdBox.Background = Brushes.White;
                                                    drpDwnMailRxFrameIdBox.IsSynchronizedWithCurrentItem = true;
                                                    drpDwnMailRxFrameIdBox.SelectionChanged += drpDwnMailTxFrameIdBoxs_SelectionChanged;

                                                    ComboBox drpDwnMailRxMessageBox = new ComboBox();
                                                    drpDwnMailRxMessageBox.Name = "MailMessage" + ind + "_Val";
                                                    drpDwnMailRxMessageBox.FontSize = 12;
                                                    drpDwnMailRxMessageBox.FontWeight = FontWeights.Bold;
                                                    drpDwnMailRxMessageBox.Height = 30;
                                                    drpDwnMailRxMessageBox.Width = 280;
                                                    drpDwnMailRxMessageBox.Background = Brushes.White;
                                                    drpDwnMailRxMessageBox.IsSynchronizedWithCurrentItem = true;
                                                    drpDwnMailRxMessageBox.SelectionChanged += drpDwnMailTxMessageBoxs_SelectionChanged; ;
                                                    List<string> txMsgsFrameid = new List<string>();
                                                    txMsgsFrameid.Add(txMoreMessagesFrameids[ind]);
                                                    List<string> txMsgs = new List<string>();
                                                    txMsgs.Add(txMoreMessages[ind]);
                                                    foreach (string frid in txMessagesFrameIdRemaing)
                                                    {
                                                        txMsgsFrameid.Add(frid);
                                                    }
                                                    foreach (string txm in txMessagesRemaing)
                                                    {
                                                        txMsgs.Add(txm);
                                                    }
                                                    drpDwnMailRxFrameIdBox.ItemsSource = txMsgsFrameid;
                                                    drpDwnMailRxMessageBox.ItemsSource = txMsgs;

                                                    TextBox txtBoxMaskValue = new TextBox();
                                                    txtBoxMaskValue.Text = mailBoxMaskValueMore[selectedMailBox][ind];
                                                    txtBoxMaskValue.FontSize = 12;
                                                    txtBoxMaskValue.FontWeight = FontWeights.Bold;
                                                    txtBoxMaskValue.Height = 30;
                                                    txtBoxMaskValue.Background = Brushes.White;
                                                    txtBoxMaskValue.IsEnabled = true;
                                                    txtBoxMaskValue.Width = 280;

                                                    txtBoxMaskValue.Name = "txtMask" + ind + "_Val";

                                                    listBoxFrameId.Items.Add(drpDwnMailRxFrameIdBox);
                                                    listBoxMessage.Items.Add(drpDwnMailRxMessageBox);
                                                    listBoxMessageMaskValue.Items.Add(txtBoxMaskValue);

                                                }

                                            }
                                        }
                                        //end


                                    }

                                    txMessagesFrameIdRemaing.Insert(0, mailBoxFrameIdRx[mailbox]);
                                    txMessagesRemaing.Insert(0, mailBoxMessageRx[mailbox]);
                                    drMailMessage.SelectedIndex = 0;
                                    txtDLC.Text = mailBoxDLCRx[mailbox];
                                    txtMaskValue.Text = mailBoxMaskValueRx[mailbox];
                                }
                                //e1


                            }

                        }
                        else
                        {
                            lblMaskValueBox.Text = "Mask Value";
                            lblMaskValueBox.ToolTip = " Mask Value";
                            lblDLCTX.ToolTip = "DLC";
                            lblDLCTX.Text = "DLC";
                            lblTxBox.Text = "Message";
                            lblTxBox.ToolTip = "Message";
                            lblTxFrameIdBox.ToolTip = "Message Frame Id";
                            lblTxFrameIdBox.Text = "Message FrameId";
                            if (mailBoxCanif.ContainsKey(mailbox))
                            {
                                btnSubmit.IsEnabled = true;
                                btnSubmit.Content = "Edit/Update";
                            }
                            else
                            {
                                btnSubmit.Content = "Submit";
                                btnSubmit.IsEnabled = false;
                            }

                            drMailFrameId.IsEnabled = false;
                            drMailMessage.IsEnabled = false;
                            txtDLC.IsEnabled = false;
                            txtMaskValue.IsEnabled = false;

                            txtDLC.Text = "";
                            txtMaskValue.Text = "";



                        }




                    }

                }



            }
            catch (Exception ex)
            {
                Logger.Log.Instance.Error("Exception encountered with message: " + ex.Message);
            }
            //end




        }

        private void drpDwnTxRx_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

            var dd = (sender as ComboBox);
            selectedType = (string)dd.SelectedItem;
        }
        private void drpDwnRxNetworkBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var textReceptionTimeout = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[1];
            var drpRxSignal = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[4];
            var textRxCallBackFunction = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[2];
            var textReceptionTimeoutCallBack = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[3];
            textReceptionTimeout.Text = "";
            var dd = (sender as ComboBox);
            string sItem = (string)dd.SelectedItem;
            if (sItem != null && !sItem.Equals(""))
            {
                selectedRxMessage = sItem.Substring(0, sItem.IndexOf("("));
                if (rxReceptionTimeout.ContainsKey(selectedRxMessage))
                {
                    textReceptionTimeout.Text = rxReceptionTimeout[selectedRxMessage];
                }

                List<String> lvaluesSignalRx = new List<String>();
                messagesRxSignal.TryGetValue(selectedRxMessage, out lvaluesSignalRx);
                if (lvaluesSignalRx != null && lvaluesSignalRx.Count > 0)
                {
                    selectedSignalRx = lvaluesSignalRx[0];
                    drpRxSignal.ItemsSource = (lvaluesSignalRx).ToList();

                    if (rxReceptionCallBackFunction.ContainsKey(selectedSignalRx))
                    {
                        textRxCallBackFunction.Text = rxReceptionCallBackFunction[selectedSignalRx];
                    }
                    else
                    {
                        textRxCallBackFunction.Text = "";
                    }

                    if (rxReceptionTimeoutCallBack.ContainsKey(selectedSignalRx))
                    {
                        textReceptionTimeoutCallBack.Text = rxReceptionTimeoutCallBack[selectedSignalRx];
                    }
                    else
                    {
                        textReceptionTimeoutCallBack.Text = "";
                    }


                }
                else
                {

                    lvaluesSignalRx = new List<String>();
                    drpRxSignal.ItemsSource = (lvaluesSignalRx).ToList();
                    selectedSignalRx = "";
                    textRxCallBackFunction.Text = "";
                    textReceptionTimeoutCallBack.Text = "";


                }
            }
            else
            {
                selectedRxMessage = "";
                selectedSignalRx = "";

            }
        }
        private void drpDwnTxNetworkBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var dd = (sender as ComboBox);
            string sItem = (string)dd.SelectedItem;
            if (sItem != null && !sItem.Equals(""))
            {
                selectedTxMessage = sItem.Substring(0, sItem.IndexOf("("));
            }
            else
            {
                selectedTxMessage = "";
            }
            var drpDwnSignal = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[2];
            var textBoxInitialValue = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[0];


            if (selectedTxMessage != null && !selectedTxMessage.Equals(""))
            {
                List<String> lvaluesSignal = new List<String>();
                messagesTxSignal.TryGetValue(selectedTxMessage, out lvaluesSignal);
                if (lvaluesSignal != null && lvaluesSignal.Count > 0)
                {
                    selectedSignal = lvaluesSignal[0];
                    drpDwnSignal.ItemsSource = (lvaluesSignal).ToList();

                    List<String> lsIntitials = messagesIntitials[selectedTxMessage];
                    try
                    {
                        string defIn = lsIntitials.Contains(selectedSignal) ? lsIntitials[lsIntitials.IndexOf(selectedSignal) + 1] : "0";
                        textBoxInitialValue.Text = messagesTxInitialsConfig.ContainsKey(selectedSignal) ? messagesTxInitialsConfig[selectedSignal] : defIn;
                    }
                    catch (Exception ex)
                    {
                        textBoxInitialValue.Text = "";
                        Logger.Log.Instance.Error("Exception encountered with message: " + ex.Message);

                    }


                }
                else
                {
                    selectedTxMessage = "";
                    lvaluesSignal = new List<String>();
                    drpDwnSignal.ItemsSource = (lvaluesSignal).ToList();
                    selectedSignal = "";
                    textBoxInitialValue.Text = "";

                }

            }
            else
            {
                selectedTxMessage = "";
                List<String> lvaluesSignal = new List<String>();
                drpDwnSignal.ItemsSource = (lvaluesSignal).ToList();
                selectedSignal = "";
                textBoxInitialValue.Text = "";

            }

        }

        private void txtBoxRXS_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            string txValue = tx.Text;

            if (txValue != null && !txValue.Trim().Equals(""))
            {
                selectMailBoxMessageRx = txValue;

            }
        }
        private void txtBoxTXS_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            string txValue = tx.Text;

            if (txValue != null && !txValue.Trim().Equals(""))
            {
                selectMailBoxMessage = txValue;

            }
        }

        private void txtBoxRXSM_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            string txValue = tx.Text;

            if (txValue != null && !txValue.Trim().Equals(""))
            {
                selectMailBoxFrameIdRx = txValue;

            }
        }

        private void txtBoxTXSM_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            string txValue = tx.Text;

            if (txValue != null && !txValue.Trim().Equals(""))
            {
                selectMailBoxFrameId = txValue;

            }
        }


        private void txtBoxDLCRx_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            string txValue = tx.Text;

            if (txValue != null && !txValue.Trim().Equals(""))
            {
                selectMailBoxDLCRx = txValue;

            }
        }
        private void txtBoxDLC_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            string txValue = tx.Text;

            if (txValue != null && !txValue.Trim().Equals(""))
            {
                selectMailBoxDLC = txValue;

            }
        }

        private void txtBoxMaskValueRX_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            string txValue = tx.Text;

            if (txValue != null && !txValue.Trim().Equals(""))
            {


                selectMailBoxMaskValueRx = txValue;



            }
        }

        private void txtBoxMaskValue_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            string txValue = tx.Text;

            if (txValue != null && !txValue.Trim().Equals(""))
            {
                selectMailBoxMaskValue = txValue;

            }
        }
        private void txtBoxInitial_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            string txValue = tx.Text;
            if (selectedSignal != null && !selectedSignal.Equals("") && txValue != null && !txValue.Trim().Equals(""))
            {
                messagesTxInitialsConfig[selectedSignal] = txValue;
            }



        }
        private void txtBoxScale_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            string txValue = tx.Text;
            if (selectedSignal != null && !selectedSignal.Equals("") && txValue != null && !txValue.Trim().Equals(""))
            {
                messagesTxScale[selectedSignal] = txValue;
            }



        }

        private void txtBoxWaitforSleepTimeout_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            WaitforSleepTimeout = tx.Text;


        }
        private void txtBoxMAINFUNCTION_PERIOD_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            MAINFUNCTION_PERIOD = tx.Text;
        }


        private void txtBoxRowStateMachineTimeoutLimit_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            StateMachineTimeout = tx.Text;


        }
        private void txtBoxAPPLICATION_BUSOFF_INDICATION_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            APPLICATION_BUSOFF_INDICATION = tx.Text;
        }

        private void txtBoxAPPLICATION_NETWORK_REQUEST_CBK_FUNC_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            APPLICATION_NETWORK_REQUEST_CBK_FUNC = tx.Text;
        }
        private void txtBoxAPPLICATION_WAKEUP_CBK_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            APPLICATION_WAKEUP_CBK = tx.Text;
        }
        private void txtBoxRxCallbackFunctionOut_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            string txValue = tx.Text;
            var drpRxSignal = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[4];
            selectedSignalRx = (string)drpRxSignal.SelectedItem;
            if (selectedSignalRx != null)
            {
                rxReceptionTimeoutCallBack[selectedSignalRx] = txValue;
            }
        }
        private void txtBoxRxCallbackFunction_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            string txValue = tx.Text;
            if (txValue != null && !txValue.Trim().Equals(""))
            {
                var drpRxSignal = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[4];
                selectedSignalRx = (string)drpRxSignal.SelectedItem;
                if (selectedSignalRx != null)
                {
                    rxReceptionCallBackFunction[selectedSignalRx] = txValue;
                }


            }
        }

        private void txtBoxReceptionTime_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            string txValue = tx.Text;
            if (selectedRxMessage != null && !selectedRxMessage.Equals("") && txValue != null && !txValue.Trim().Equals(""))
            {
                if (rxReceptionTimeout.ContainsKey(selectedRxMessage))
                {
                    rxReceptionTimeout[selectedRxMessage] = txValue;
                }
                else
                {
                    rxReceptionTimeout.Add(selectedRxMessage, txValue);
                }
            }

        }

        private void txtBoxOffset_TextChanged(object sender, EventArgs e)
        {
            var tx = (sender as TextBox);
            string txValue = tx.Text;
            if (selectedSignal != null && !selectedSignal.Equals("") && txValue != null && !txValue.Trim().Equals(""))
            {
                messagesTxOffset[selectedSignal] = txValue;
            }



        }



        private void drpDwnSignalRx_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var dd = (sender as ComboBox);
            string sItem = (string)dd.SelectedItem;
            selectedSignal = sItem;
            var textBoxCallBackFunction = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[2];
            var textBoxCallBackTimeout = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[3];
            if (selectedSignal != null && !selectedSignal.Trim().Equals(""))
            {

                textBoxCallBackFunction.Text = rxReceptionCallBackFunction.ContainsKey(selectedSignal) ? rxReceptionCallBackFunction[selectedSignal] : "";
                textBoxCallBackTimeout.Text = rxReceptionTimeoutCallBack.ContainsKey(selectedSignal) ? rxReceptionTimeoutCallBack[selectedSignal] : "";

            }
            else
            {
                textBoxCallBackFunction.Text = "";
                textBoxCallBackTimeout.Text = "";
            }

        }


        private void drpDwnSignal_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var dd = (sender as ComboBox);
            string sItem = (string)dd.SelectedItem;
            selectedSignal = sItem;
            if (selectedSignal != null && !selectedSignal.Trim().Equals(""))
            {
                var textBoxInitialValue = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[0];
                try
                {

                    // textBoxInitialValue.Text = messagesTxInitialsConfig.ContainsKey(selectedSignal) ? messagesTxInitialsConfig[selectedSignal] : (messagesIntitials.ContainsKey(selectedSignal) ? messagesIntitials[selectedTxMessage][messagesIntitials[selectedTxMessage].IndexOf(selectedSignal) + 1] : "0");
                    if (messagesTxInitialsConfig.ContainsKey(selectedSignal))
                    {
                        textBoxInitialValue.Text = messagesTxInitialsConfig[selectedSignal];
                    }
                    else
                    {
                        List<String> lsIntitials = messagesIntitials[selectedTxMessage];
                        List<String> lsIntitialsFact = messagesIntitialsFact[selectedTxMessage];
                        List<String> lsIntitialsOffset = messagesIntitialsOffset[selectedTxMessage];
                        double initial = 0;
                        double inti = 0;
                        double intiFact = 0;
                        double intiOffset = 0;
                        try
                        {
                            inti = Double.Parse(lsIntitials.Contains(selectedSignal) ? lsIntitials[lsIntitials.IndexOf(selectedSignal) + 1] : "0");
                        }
                        catch (Exception ex)
                        {
                            Logger.Log.Instance.Error("Exception encountered with message: " + ex.Message);
                        }
                        try
                        {
                            intiFact = Double.Parse(lsIntitialsFact.Contains(selectedSignal) ? lsIntitialsFact[lsIntitialsFact.IndexOf(selectedSignal) + 1] : "0");
                        }
                        catch (Exception ex)
                        {
                            Logger.Log.Instance.Error("Exception encountered with message: " + ex.Message);
                        }
                        try
                        {
                            intiOffset = Double.Parse(lsIntitialsOffset.Contains(selectedSignal) ? lsIntitialsOffset[lsIntitialsFact.IndexOf(selectedSignal) + 1] : "0");
                        }
                        catch (Exception ex)
                        {
                            Logger.Log.Instance.Error("Exception encountered with message: " + ex.Message);
                        }
                        initial = (inti * intiFact + intiOffset);
                        textBoxInitialValue.Text = Convert.ToInt32(Math.Round(initial, 0, MidpointRounding.AwayFromZero)) + "";
                    }



                }
                catch (Exception ex)
                {
                    textBoxInitialValue.Text = "";
                    Logger.Log.Instance.Error("Exception encountered with message: " + ex.Message);
                }

            }

        }
        private void SaveCanMgrConfig_Click(object sender, RoutedEventArgs e)
        {
            DoSerialization();
            MessageBox.Show("saved successfully");
        }


        private void drpDwnNetworkBoxS_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            try
            {
                if (fnamec != null && !fnamec.Trim().Equals(""))
                {
                    var drMailBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[0];
                    var drMailCanIf = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[1];
                    var drNetworkNode = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[2];

                    var drMailFrameId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[3];
                    var drMailMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[4];

                    var txtDLC = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[0];

                    var txtMaskValue = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[1];
                    var btnAddMore = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<Button>().ToList()[0];
                    var btnSubmit = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<Button>().ToList()[1];
                    var btnRemove = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<Button>().ToList()[2];
                    string canifMailBox = (string)drMailCanIf.SelectedItem;
                    String mailbox = (string)drMailBox.SelectedItem;
                    selectedMailBox = mailbox;
                    var lblTxFrameIdBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBlock>().ToList()[3];
                    var lblTxBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBlock>().ToList()[4];
                    var lblDLCTX = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBlock>().ToList()[5];
                    var lblMaskValueBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBlock>().ToList()[6];

                    var listBoxFrameId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[0];
                    var listBoxMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[1];
                    var listBoxMessageMaskValue = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[2];

                    listBoxFrameId.Items.Clear();
                    listBoxMessage.Items.Clear();
                    listBoxMessageMaskValue.Items.Clear();
                    if (canifMailBox != null)
                    {

                        btnSubmit.IsEnabled = true;
                        btnAddMore.IsEnabled = false;
                        drMailFrameId.IsEnabled = true;
                        drMailMessage.IsEnabled = true;
                        txtDLC.IsEnabled = false;
                        txtMaskValue.IsEnabled = true;
                        if (mailBoxCanifNode.ContainsKey(mailbox) && mailBoxCanif.ContainsKey(mailbox) && mailBoxCanif[mailbox].Equals(canifMailBox))
                        {
                            // drNetworkNode.SelectedIndex = allNodes.IndexOf(mailBoxCanifNode[mailbox]);
                        }
                        String selectedNode = (string)drNetworkNode.SelectedItem;

                        if (canifMailBox.Equals("CANIF_RxBasicCANMailbox") || canifMailBox.Equals("CANIF_RxFullCANMailbox"))
                        {
                            if (canifMailBox.Equals("CANIF_RxBasicCANMailbox") && sender == drMailCanIf && btnSubmit.Content.ToString().Equals("Submit"))
                            {
                                MessageBox.Show("Development is under progress");
                            }

                            lblMaskValueBox.Text = "Rx Mask Value";
                            lblMaskValueBox.ToolTip = "Rx Mask Value";
                            lblDLCTX.ToolTip = "Rx DLC";
                            lblDLCTX.Text = "Rx DLC";
                            lblTxBox.Text = "Rx Message";
                            lblTxBox.ToolTip = "Rx Message";
                            lblTxFrameIdBox.ToolTip = "Rx Message Frame Id";
                            lblTxFrameIdBox.Text = "Rx Message FrameId";


                            if (true)
                            {
                                List<string> onlyRxMessageAlloted = new List<string>();
                                List<string> onlyRxMessageFrameIdAlloted = new List<string>();
                                foreach (KeyValuePair<string, string> kvp in mailBoxMessageRx)
                                {
                                    onlyRxMessageAlloted.Add(kvp.Value);
                                    onlyRxMessageFrameIdAlloted.Add(messagesRxFrameIds[kvp.Value]);

                                }
                                foreach (KeyValuePair<string, List<String>> kvp in mailBoxMessageMoreRx)
                                {
                                    List<String> ls = kvp.Value;
                                    if (ls != null)
                                    {
                                        foreach (String s in ls)
                                        {
                                            onlyRxMessageAlloted.Add(s);
                                            onlyRxMessageFrameIdAlloted.Add(messagesRxFrameIds[s]);
                                        }
                                    }

                                }
                                List<string> rxMessagesRemaing = new List<string>();
                                List<string> rxMessagesFrameIdRemaing = new List<string>();
                                List<string> allRxMessagesNode = rxMessage.ContainsKey(selectedNode) ? rxMessage[selectedNode] : null;
                                if (allRxMessagesNode != null && allRxMessagesNode.Count > 0)
                                {
                                    foreach (string message in allRxMessagesNode)
                                    {
                                        if (!onlyRxMessageAlloted.Contains(message))
                                        {
                                            rxMessagesRemaing.Add(message);
                                            rxMessagesFrameIdRemaing.Add(messagesRxFrameIds[message]);
                                        }
                                    }
                                }

                                if (mailBoxCanif.ContainsKey(mailbox))
                                {
                                    btnSubmit.Content = "Edit/Update";
                                    btnSubmit.IsEnabled = true;
                                    btnAddMore.IsEnabled = false;

                                    if (canifMailBox.Equals("CANIF_RxBasicCANMailbox"))
                                    {
                                        //start
                                        btnAddMore.IsEnabled = true;

                                        if (mailBoxMessageMoreRx.ContainsKey(selectedMailBox))
                                        {
                                            List<string> rxMoreMessagesFrameids = mailBoxFrameIdMoreRx[selectedMailBox];
                                            List<string> rxMoreMessages = mailBoxMessageMoreRx[selectedMailBox];
                                            if (rxMoreMessagesFrameids != null && rxMoreMessagesFrameids.Count > 0)
                                            {
                                                btnRemove.IsEnabled = true;
                                                for (int ind = 0; ind < rxMoreMessagesFrameids.Count; ind++)
                                                {

                                                    ComboBox drpDwnMailRxFrameIdBox = new ComboBox();
                                                    drpDwnMailRxFrameIdBox.Name = "MailFrame" + ind + "_Val";
                                                    drpDwnMailRxFrameIdBox.FontSize = 12;
                                                    drpDwnMailRxFrameIdBox.FontWeight = FontWeights.Bold;
                                                    drpDwnMailRxFrameIdBox.Height = 30;
                                                    drpDwnMailRxFrameIdBox.Width = 280;
                                                    drpDwnMailRxFrameIdBox.Background = Brushes.White;
                                                    drpDwnMailRxFrameIdBox.IsSynchronizedWithCurrentItem = true;
                                                    drpDwnMailRxFrameIdBox.SelectionChanged += drpDwnMailTxFrameIdBoxs_SelectionChanged;

                                                    ComboBox drpDwnMailRxMessageBox = new ComboBox();
                                                    drpDwnMailRxMessageBox.Name = "MailMessage" + ind + "_Val";
                                                    drpDwnMailRxMessageBox.FontSize = 12;
                                                    drpDwnMailRxMessageBox.FontWeight = FontWeights.Bold;
                                                    drpDwnMailRxMessageBox.Height = 30;
                                                    drpDwnMailRxMessageBox.Width = 280;
                                                    drpDwnMailRxMessageBox.Background = Brushes.White;
                                                    drpDwnMailRxMessageBox.IsSynchronizedWithCurrentItem = true;
                                                    drpDwnMailRxMessageBox.SelectionChanged += drpDwnMailTxMessageBoxs_SelectionChanged; ;
                                                    List<string> rxMsgsFrameid = new List<string>();
                                                    rxMsgsFrameid.Add(rxMoreMessagesFrameids[ind]);
                                                    List<string> rxMsgs = new List<string>();
                                                    rxMsgs.Add(rxMoreMessages[ind]);
                                                    foreach (string frid in rxMessagesFrameIdRemaing)
                                                    {
                                                        rxMsgsFrameid.Add(frid);
                                                    }
                                                    foreach (string rxm in rxMessagesRemaing)
                                                    {
                                                        rxMsgs.Add(rxm);
                                                    }
                                                    drpDwnMailRxFrameIdBox.ItemsSource = rxMsgsFrameid;
                                                    drpDwnMailRxMessageBox.ItemsSource = rxMsgs;

                                                    TextBox txtBoxMaskValue = new TextBox();
                                                    txtBoxMaskValue.Text = mailBoxMaskValueMoreRx[selectedMailBox][ind];
                                                    txtBoxMaskValue.FontSize = 12;
                                                    txtBoxMaskValue.FontWeight = FontWeights.Bold;
                                                    txtBoxMaskValue.Height = 30;
                                                    txtBoxMaskValue.Background = Brushes.White;
                                                    txtBoxMaskValue.IsEnabled = true;
                                                    txtBoxMaskValue.Width = 280;

                                                    txtBoxMaskValue.Name = "txtMask" + ind + "_Val";

                                                    listBoxFrameId.Items.Add(drpDwnMailRxFrameIdBox);
                                                    listBoxMessage.Items.Add(drpDwnMailRxMessageBox);
                                                    listBoxMessageMaskValue.Items.Add(txtBoxMaskValue);

                                                }

                                            }

                                        }

                                        //end


                                    }


                                    else
                                    {
                                        if (mailBoxFrameIdRx.ContainsKey(mailbox))
                                        {
                                            rxMessagesFrameIdRemaing.Insert(0, mailBoxFrameIdRx[mailbox]);
                                            rxMessagesRemaing.Insert(0, mailBoxMessageRx[mailbox]);


                                            txtDLC.Text = mailBoxDLCRx[mailbox];
                                            txtMaskValue.Text = mailBoxMaskValueRx[mailbox];
                                        }


                                    }
                                    String canIfMailBoxPrev = mailBoxCanif[mailbox];
                                    if (!canIfMailBoxPrev.Equals(canifMailBox))
                                    {

                                        btnAddMore.IsEnabled = false;
                                        if (mailBoxFrameIdMoreRx.ContainsKey(selectedMailBox) && allRxMessagesNode != null && allRxMessagesNode.Count > 0)
                                        {
                                            List<string> rxMoreMessagesFrameids = mailBoxFrameIdMoreRx[selectedMailBox];
                                            List<string> rxMoreMessages = mailBoxMessageMoreRx[selectedMailBox];

                                            for (int ind = 0; ind < rxMoreMessagesFrameids.Count; ind++)
                                            {
                                                if (allRxMessagesNode.Contains(rxMoreMessages[ind]))
                                                {
                                                    rxMessagesFrameIdRemaing.Add(rxMoreMessagesFrameids[ind]);
                                                    rxMessagesRemaing.Add(rxMoreMessages[ind]);
                                                }
                                            }
                                        }

                                    }
                                }
                                drMailMessage.ItemsSource = null;
                                drMailFrameId.ItemsSource = null;

                                drMailMessage.ItemsSource = rxMessagesRemaing;
                                drMailFrameId.ItemsSource = rxMessagesFrameIdRemaing;
                                drMailMessage.SelectedIndex = 0;
                                drMailFrameId.SelectedIndex = 0;
                                txtDLC.Text = messagesRxDLC.ContainsKey((string)drMailMessage.SelectedItem) ? messagesRxDLC[(string)drMailMessage.SelectedItem] : "0";



                            }


                        }
                        else if (canifMailBox.Equals("CANIF_TxBasicCANMailbox") || canifMailBox.Equals("CANIF_TxFullCANMailbox"))
                        {

                            if (canifMailBox.Equals("CANIF_TxBasicCANMailbox") && sender == drMailCanIf && btnSubmit.Content.ToString().Equals("Submit"))
                            {
                                MessageBox.Show("Development is under progress");
                            }
                            lblMaskValueBox.Text = "Tx Mask Value";
                            lblMaskValueBox.ToolTip = "Tx Mask Value";
                            lblDLCTX.ToolTip = "Tx DLC";
                            lblDLCTX.Text = "Tx DLC";
                            lblTxBox.Text = "Tx Message";
                            lblTxBox.ToolTip = "Tx Message";
                            lblTxFrameIdBox.ToolTip = "Tx Message Frame Id";
                            lblTxFrameIdBox.Text = "Tx Message FrameId";


                            if (true)
                            {
                                List<string> onlyTxMessageAlloted = new List<string>();
                                List<string> onlyTxMessageFrameIdAlloted = new List<string>();
                                foreach (KeyValuePair<string, string> kvp in mailBoxMessage)
                                {
                                    onlyTxMessageAlloted.Add(kvp.Value);
                                    onlyTxMessageFrameIdAlloted.Add(messagesTxFrameIds[kvp.Value]);

                                }
                                foreach (KeyValuePair<string, List<String>> kvp in mailBoxMessageMore)
                                {
                                    List<String> ls = kvp.Value;
                                    if (ls != null)
                                    {
                                        foreach (String s in ls)
                                        {
                                            onlyTxMessageAlloted.Add(s);
                                            onlyTxMessageFrameIdAlloted.Add(messagesTxFrameIds[s]);
                                        }
                                    }

                                }
                                List<string> txMessagesRemaing = new List<string>();
                                List<string> txMessagesFrameIdRemaing = new List<string>();
                                List<string> allTxMessagesNode = txMessage.ContainsKey(selectedNode) ? txMessage[selectedNode] : null;
                                if (allTxMessagesNode != null && allTxMessagesNode.Count > 0)
                                {
                                    foreach (string message in allTxMessagesNode)
                                    {
                                        if (!onlyTxMessageAlloted.Contains(message))
                                        {
                                            txMessagesRemaing.Add(message);
                                            txMessagesFrameIdRemaing.Add(messagesTxFrameIds[message]);
                                        }
                                    }
                                }

                                //s1
                                if (mailBoxCanif.ContainsKey(mailbox))
                                {
                                    btnSubmit.Content = "Edit/Update";
                                    btnSubmit.IsEnabled = true;
                                    btnAddMore.IsEnabled = false;
                                    if (canifMailBox.Equals("CANIF_TxBasicCANMailbox"))
                                    {
                                        btnAddMore.IsEnabled = true;
                                        //start

                                        if (mailBoxMessageMore.ContainsKey(selectedMailBox))
                                        {
                                            List<string> txMoreMessagesFrameids = mailBoxFrameIdMore[selectedMailBox];
                                            List<string> txMoreMessages = mailBoxMessageMore[selectedMailBox];
                                            if (txMoreMessagesFrameids != null && txMoreMessagesFrameids.Count > 0)
                                            {
                                                btnRemove.IsEnabled = true;
                                                for (int ind = 0; ind < txMoreMessagesFrameids.Count; ind++)
                                                {

                                                    ComboBox drpDwnMailTxFrameIdBox = new ComboBox();
                                                    drpDwnMailTxFrameIdBox.Name = "MailFrame" + ind + "_Val";
                                                    drpDwnMailTxFrameIdBox.FontSize = 12;
                                                    drpDwnMailTxFrameIdBox.FontWeight = FontWeights.Bold;
                                                    drpDwnMailTxFrameIdBox.Height = 30;
                                                    drpDwnMailTxFrameIdBox.Width = 280;
                                                    drpDwnMailTxFrameIdBox.Background = Brushes.White;
                                                    drpDwnMailTxFrameIdBox.IsSynchronizedWithCurrentItem = true;
                                                    drpDwnMailTxFrameIdBox.SelectionChanged += drpDwnMailTxFrameIdBoxs_SelectionChanged;

                                                    ComboBox drpDwnMailTxMessageBox = new ComboBox();
                                                    drpDwnMailTxMessageBox.Name = "MailMessage" + ind + "_Val";
                                                    drpDwnMailTxMessageBox.FontSize = 12;
                                                    drpDwnMailTxMessageBox.FontWeight = FontWeights.Bold;
                                                    drpDwnMailTxMessageBox.Height = 30;
                                                    drpDwnMailTxMessageBox.Width = 280;
                                                    drpDwnMailTxMessageBox.Background = Brushes.White;
                                                    drpDwnMailTxMessageBox.IsSynchronizedWithCurrentItem = true;
                                                    drpDwnMailTxMessageBox.SelectionChanged += drpDwnMailTxMessageBoxs_SelectionChanged; ;
                                                    List<string> txMsgsFrameid = new List<string>();
                                                    txMsgsFrameid.Add(txMoreMessagesFrameids[ind]);
                                                    List<string> txMsgs = new List<string>();
                                                    txMsgs.Add(txMoreMessages[ind]);
                                                    foreach (string frid in txMessagesFrameIdRemaing)
                                                    {
                                                        txMsgsFrameid.Add(frid);
                                                    }
                                                    foreach (string txm in txMessagesRemaing)
                                                    {
                                                        txMsgs.Add(txm);
                                                    }
                                                    drpDwnMailTxFrameIdBox.ItemsSource = txMsgsFrameid;
                                                    drpDwnMailTxMessageBox.ItemsSource = txMsgs;

                                                    TextBox txtBoxMaskValue = new TextBox();
                                                    txtBoxMaskValue.Text = mailBoxMaskValueMore[selectedMailBox][ind];
                                                    txtBoxMaskValue.FontSize = 12;
                                                    txtBoxMaskValue.FontWeight = FontWeights.Bold;
                                                    txtBoxMaskValue.Height = 30;
                                                    txtBoxMaskValue.Background = Brushes.White;
                                                    txtBoxMaskValue.IsEnabled = true;
                                                    txtBoxMaskValue.Width = 280;

                                                    txtBoxMaskValue.Name = "txtMask" + ind + "_Val";

                                                    listBoxFrameId.Items.Add(drpDwnMailTxFrameIdBox);
                                                    listBoxMessage.Items.Add(drpDwnMailTxMessageBox);
                                                    listBoxMessageMaskValue.Items.Add(txtBoxMaskValue);

                                                }

                                            }
                                        }
                                        //end

                                        String canIfMailBoxPrev = mailBoxCanif[mailbox];
                                        if (!canIfMailBoxPrev.Equals(canifMailBox))
                                        {

                                            btnAddMore.IsEnabled = false;
                                            if (mailBoxFrameIdMore.ContainsKey(selectedMailBox) && allTxMessagesNode != null && allTxMessagesNode.Count > 0)
                                            {
                                                List<string> txMoreMessagesFrameids = mailBoxFrameIdMore[selectedMailBox];
                                                List<string> txMoreMessages = mailBoxMessageMore[selectedMailBox];

                                                for (int ind = 0; ind < txMoreMessagesFrameids.Count; ind++)
                                                {
                                                    if (allTxMessagesNode.Contains(txMoreMessages[ind]))
                                                    {
                                                        txMessagesFrameIdRemaing.Add(txMoreMessagesFrameids[ind]);
                                                        txMessagesRemaing.Add(txMoreMessages[ind]);
                                                    }
                                                }
                                            }
                                        }


                                    }
                                    else
                                    {
                                        if (mailBoxFrameId.ContainsKey(mailbox))
                                        {
                                            txMessagesFrameIdRemaing.Insert(0, mailBoxFrameId[mailbox]);
                                            txMessagesRemaing.Insert(0, mailBoxMessage[mailbox]);

                                            txtDLC.Text = mailBoxDLC[mailbox];
                                            txtMaskValue.Text = mailBoxMaskValue[mailbox];
                                        }

                                    }




                                }
                                //e1
                                drMailMessage.ItemsSource = null;
                                drMailFrameId.ItemsSource = null;

                                drMailMessage.ItemsSource = txMessagesRemaing;
                                drMailFrameId.ItemsSource = txMessagesFrameIdRemaing;
                                drMailMessage.SelectedIndex = 0;
                                txtDLC.Text = messagesTxDLC.ContainsKey((string)drMailMessage.SelectedItem) ? messagesTxDLC[(string)drMailMessage.SelectedItem] : "0";

                            }

                        }
                        else
                        {
                            lblMaskValueBox.Text = "Mask Value";
                            lblMaskValueBox.ToolTip = " Mask Value";
                            lblDLCTX.ToolTip = "DLC";
                            lblDLCTX.Text = "DLC";
                            lblTxBox.Text = "Message";
                            lblTxBox.ToolTip = "Message";
                            lblTxFrameIdBox.ToolTip = "Message Frame Id";
                            lblTxFrameIdBox.Text = "Message FrameId";
                            if (mailBoxCanif.ContainsKey(mailbox))
                            {
                                btnSubmit.IsEnabled = true;
                                btnSubmit.Content = "Edit/Update";
                            }
                            else
                            {
                                btnSubmit.Content = "Submit";
                                btnSubmit.IsEnabled = false;
                            }

                            drMailFrameId.IsEnabled = false;
                            drMailMessage.IsEnabled = false;
                            txtDLC.IsEnabled = false;
                            txtMaskValue.IsEnabled = false;

                            txtDLC.Text = "";
                            txtMaskValue.Text = "";
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Logger.Log.Instance.Error("Exception encountered with message: " + ex.Message);
            }
        }


        private void drpDwnNetworkBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {


            var dd = (sender as ComboBox);
            string sItem = (string)dd.SelectedItem;
            if (sItem != null && !sItem.Trim().Equals(""))
            {
                var grd = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[1];
                var grdR = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[3];
                var drpDwnSignal = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[2];
                var drpDwnSignalRx = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[4];
                var textBoxInitialValue = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[0];

                var textBoxReceptionTime = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[1];
                var textBoxCallBackFunction = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[2];
                var textBoxReceptionTimeCallBack = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[3];
                List<String> lvaluesTx = new List<String>();
                List<String> lvaluesRx = new List<String>();

                selectedNode = sItem;
                txMessageWithFrameId.TryGetValue(sItem, out lvaluesTx);
                if (lvaluesTx != null && lvaluesTx.Count > 0)
                {
                    grd.ItemsSource = (lvaluesTx).ToList();
                    List<String> lvaluesSignal = new List<String>();
                    messagesTxSignal.TryGetValue(lvaluesTx[0].Substring(0, lvaluesTx[0].IndexOf("(")), out lvaluesSignal);
                    if (lvaluesSignal != null && lvaluesSignal.Count > 0)
                    {
                        selectedSignal = lvaluesSignal[0];
                        selectedTxMessage = lvaluesTx[0].Substring(0, lvaluesTx[0].IndexOf("("));
                        drpDwnSignal.ItemsSource = (lvaluesSignal).ToList();
                        try
                        {
                            textBoxInitialValue.Text = messagesTxInitialsConfig.ContainsKey(selectedSignal) ? messagesTxInitialsConfig[selectedSignal] : (messagesIntitials.ContainsKey(selectedSignal) ? messagesIntitials[selectedTxMessage][messagesIntitials[selectedTxMessage].IndexOf(selectedSignal) + 1] : "0");
                        }
                        catch (Exception ex)
                        {
                            textBoxInitialValue.Text = "";
                            Logger.Log.Instance.Error("Exception encountered with message: " + ex.Message);
                        }

                    }
                    else
                    {
                        selectedTxMessage = "";
                        lvaluesSignal = new List<String>();
                        drpDwnSignal.ItemsSource = (lvaluesSignal).ToList();
                        selectedSignal = "";
                        textBoxInitialValue.Text = "0";

                    }
                }
                else
                {
                    lvaluesTx = new List<String>();
                    grd.ItemsSource = (lvaluesTx).ToList();
                    List<String> lvaluesSignal = new List<String>();
                    drpDwnSignal.ItemsSource = (lvaluesSignal).ToList();
                    selectedSignal = "";
                    textBoxInitialValue.Text = "";

                }




                textBoxReceptionTime.Text = "";
                rxMessageWithFrameId.TryGetValue(sItem, out lvaluesRx);
                if (lvaluesRx != null && lvaluesRx.Count > 0)
                {
                    grdR.ItemsSource = (lvaluesRx).ToList();
                    selectedRxMessage = lvaluesRx[0].Substring(0, lvaluesRx[0].IndexOf("("));
                    if (rxReceptionTimeout.ContainsKey(selectedRxMessage))
                    {
                        textBoxReceptionTime.Text = rxReceptionTimeout[selectedRxMessage];
                    }

                }
                else
                {
                    lvaluesRx = new List<String>();
                    grdR.ItemsSource = (lvaluesRx).ToList();

                }
            }




        }
        private void drpDwnMailBoxs_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            try
            {
                var dd = (sender as ComboBox);
                string mailBox = (string)dd.SelectedItem;
                if (mailBoxCanif.ContainsKey(mailBox))
                {
                    var btnSubmit = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<Button>().ToList()[1];
                    btnSubmit.Content = "Edit/Update";
                    var drNetworkNode = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[2];
                    drNetworkNode.SelectedIndex = allNodes.IndexOf(mailBoxCanifNode[mailBox]);
                    drpDwnNetworkBoxS_SelectionChanged(drNetworkNode, null);
                    var drMailCanIf = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[1];
                    drMailCanIf.SelectedIndex = 0;
                    drMailCanIf.SelectedIndex = listCanIf.IndexOf(mailBoxCanif[mailBox]);




                }
                else
                {
                    var drMailBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[0];
                    var drMailCanIf = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[1];
                    var drNetworkNode = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[2];
                    var drMailFrameId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[3];
                    var drMailMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[4];
                    drMailCanIf.SelectedIndex = 0;
                    int nid = drNetworkNode.SelectedIndex;
                    drNetworkNode.SelectedIndex = 0;
                    drNetworkNode.SelectedIndex = nid;
                    var txtDLC = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[1];
                    var txtMaskValue = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[1];
                    var btnAddMore = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<Button>().ToList()[0];
                    var btnSubmit = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<Button>().ToList()[1];
                    var btnRemove = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<Button>().ToList()[2];
                    btnSubmit.Content = "Submit";
                    drMailFrameId.IsEnabled = false;
                    drMailMessage.IsEnabled = false;
                    txtMaskValue.IsEnabled = false;
                    txtDLC.IsEnabled = false;
                    btnAddMore.IsEnabled = false;
                    btnSubmit.IsEnabled = false;
                    btnSubmit.Content = "Submit";
                    btnRemove.IsEnabled = false;
                }





            }
            catch (Exception ex)
            {
                Logger.Log.Instance.Error("Exception encountered with message: " + ex.Message);
            }



        }

        private void drpDwnMailBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var dd = (sender as ComboBox);
            var sItem = dd.SelectedItem;
            selectedMailBox = (string)sItem;
            var grd = SpForDynamicGrid.Children.OfType<Grid>().FirstOrDefault();

            if (grd != null)
            {
                GetUpdatedValuesForConfigGeneration();
                var currSelectedMailBox = grd.Children
                                            .OfType<ComboBox>()
                                            .Where(cb => cb.Name == dd.Name.ToString())
                                            .FirstOrDefault();

                var a1 = DockingManagerModelHelper.Configuration.ARPACKAGES.Where(a => a.SHORTNAME == DockingManagerModelHelper.ModuleName).FirstOrDefault();
                var a2 = a1.ELEMENTS.ECUCMODULECONFIGURATIONVALUES.CONTAINERS.SUBCONTAINERS.Where(b => b.SUBCONTAINERS.Length > 1).FirstOrDefault();
                var currentConfigParamChild = a2.SUBCONTAINERS.Where(c => c.SHORTNAME.Equals(currSelectedMailBox.SelectedValue.ToString(), StringComparison.OrdinalIgnoreCase)).FirstOrDefault();

                string strEnableControls = a2.SUBCONTAINERS.Where(c => c.SHORTNAME.Equals(currSelectedMailBox.SelectedValue.ToString(), StringComparison.OrdinalIgnoreCase)).Select(c => c.PARAMETERVALUES.VALUE.Value).FirstOrDefault();

                // Enable/Disable the checkbox for the parent MailBox
                var tlist = grd.Children.OfType<CheckBox>().ToList();
                var currSelectedMailBoxCB = grd.Children
                                            .OfType<CheckBox>()
                                            .Where(cb => cb.Name == currSelectedMailBox.Name.ToString())
                                            .FirstOrDefault();
                if (currSelectedMailBoxCB != null)
                {
                    if (strEnableControls.Equals("ENABLE", StringComparison.OrdinalIgnoreCase))
                        currSelectedMailBoxCB.IsChecked = true;
                    else
                        currSelectedMailBoxCB.IsChecked = false;
                }

                for (int i = 0; i < currentConfigParamChild.SUBCONTAINERS.Length; i++)
                {
                    var currentConfigParamName = currentConfigParamChild.SUBCONTAINERS[i].PARAMETERVALUES.DEFINITIONREF.Value;
                    var currentConfigParamValue = currentConfigParamChild.SUBCONTAINERS[i].PARAMETERVALUES.VALUE.Value;
                }

                if (currSelectedMailBox == null)
                {
                    // This config property was not rendered before. Choose the 1st item as default
                }
                else
                {
                    //Below loop will is used to change the values of the controls based on the dropdown selection.
                    foreach (var child in grd.Children)
                    {
                        switch (child.GetType().Name.ToLower())
                        {
                            case "textblock":
                                var c1 = child as System.Windows.Controls.TextBlock;
                                if (c1.Name.Equals(currentConfigParamChild.SUBCONTAINERS.Where(a => a.PARAMETERVALUES.DEFINITIONREF.name.Equals(c1.Name, StringComparison.OrdinalIgnoreCase)).Select(a => a.PARAMETERVALUES.DEFINITIONREF.name).FirstOrDefault(), StringComparison.OrdinalIgnoreCase))
                                    c1.Text = currentConfigParamChild.SUBCONTAINERS.Where(a => a.PARAMETERVALUES.DEFINITIONREF.name.Equals(c1.Name, StringComparison.OrdinalIgnoreCase)).Select(a => a.PARAMETERVALUES.DEFINITIONREF.Value).FirstOrDefault();
                                break;
                            case "textbox":
                                var c2 = child as System.Windows.Controls.TextBox;
                                string str = currentConfigParamChild.SUBCONTAINERS.Where(a => a.PARAMETERVALUES.DEFINITIONREF.name.Equals(c2.Name.Substring(0, c2.Name.IndexOf("_Val")), StringComparison.OrdinalIgnoreCase)).Select(a => a.PARAMETERVALUES.DEFINITIONREF.name).FirstOrDefault();
                                if (c2.Name.Equals(str + "_Val", StringComparison.OrdinalIgnoreCase))
                                {
                                    c2.Text = currentConfigParamChild.SUBCONTAINERS.Where(a => a.PARAMETERVALUES.DEFINITIONREF.name.Equals(str, StringComparison.OrdinalIgnoreCase)).Select(a => a.PARAMETERVALUES.VALUE.Value).FirstOrDefault();
                                    if (strEnableControls.Equals("ENABLE", StringComparison.OrdinalIgnoreCase))
                                        c2.IsEnabled = true;
                                    else
                                        c2.IsEnabled = false;
                                }

                                break;
                            case "checkbox":
                                var c3 = child as System.Windows.Controls.CheckBox;
                                string strCB = currentConfigParamChild.SUBCONTAINERS.Where(a => a.PARAMETERVALUES.DEFINITIONREF.name.Equals(c3.Name.Substring(0, c3.Name.IndexOf("_Val")), StringComparison.OrdinalIgnoreCase)).Select(a => a.PARAMETERVALUES.DEFINITIONREF.name).FirstOrDefault();
                                if (c3.Name.Equals(strCB + "_Val", StringComparison.OrdinalIgnoreCase))
                                {
                                    c3.IsChecked = currentConfigParamChild.SUBCONTAINERS.Where(a => a.PARAMETERVALUES.DEFINITIONREF.name.Equals(strCB, StringComparison.OrdinalIgnoreCase)).Select(a => a.PARAMETERVALUES.VALUE.Value).FirstOrDefault().ToString().Equals("ENABLE") ? true : false;
                                    if (strEnableControls.Equals("ENABLE", StringComparison.OrdinalIgnoreCase))
                                        c3.IsEnabled = true;
                                    else
                                        c3.IsEnabled = false;
                                }
                                break;
                            case "combobox":
                                var c4 = child as System.Windows.Controls.ComboBox;
                                string strCmb = currentConfigParamChild.SUBCONTAINERS.Where(a => a.PARAMETERVALUES.DEFINITIONREF.name.Equals(c4.Name.Substring(0, c4.Name.IndexOf("_Val")), StringComparison.OrdinalIgnoreCase)).Select(a => a.PARAMETERVALUES.DEFINITIONREF.name).FirstOrDefault();
                                if (c4.Name.Equals(strCmb + "_Val", StringComparison.OrdinalIgnoreCase))
                                {
                                    c4.SelectedValue = currentConfigParamChild.SUBCONTAINERS.Where(a => a.PARAMETERVALUES.DEFINITIONREF.name.Equals(strCmb, StringComparison.OrdinalIgnoreCase)).Select(a => a.PARAMETERVALUES.VALUE.Value).FirstOrDefault();
                                    if (strEnableControls.Equals("ENABLE", StringComparison.OrdinalIgnoreCase))
                                        c4.IsEnabled = true;
                                    else
                                        c4.IsEnabled = false;
                                }
                                break;
                        }
                    }
                }
                // DoCanIf();
            }
            DockingManagerModelHelper.SelectedMailBox = sItem.ToString();

        }

        /// <summary>
        /// To get the full path of the TreeViewItemAdv
        /// </summary>
        public string GetFullPath(TreeViewItemAdv node)
        {
            if (node == null)
                throw new ArgumentNullException();

            var result = Convert.ToString(node.Header);

            for (var i = GetParentItem(node); i != null; i = GetParentItem(i))
                result = i.Header + "\\" + result;

            return result;
        }

        /// <summary>
        /// To get the parent of the item
        /// </summary>
        static TreeViewItemAdv GetParentItem(TreeViewItemAdv item)
        {
            for (var i = VisualTreeHelper.GetParent(item); i != null; i = VisualTreeHelper.GetParent(i))
                if (i is TreeViewItemAdv)
                    return (TreeViewItemAdv)i;

            return null;
        }

        #endregion

        #region Implementation
        /// <summary>
        /// Called when [loaded].
        /// </summary>
        /// <param name="sender">The sender.</param>
        /// <param name="e">The <see cref="RoutedEventArgs"/> instance containing the event data.</param>
        private void OnLoaded(object sender, RoutedEventArgs e)
        {
            CurrentVisualStyle = "Metro";
        }

        /// <summary>
        /// On Visual Style Changed.
        /// </summary>
        /// <remarks></remarks>
        private void OnVisualStyleChanged()
        {
            VisualStyles visualStyle = VisualStyles.Default;
            Enum.TryParse(CurrentVisualStyle, out visualStyle);
            if (visualStyle != VisualStyles.Default)
            {
                SfSkinManager.ApplyStylesOnApplication = true;
                SfSkinManager.SetVisualStyle(this, visualStyle);
                SfSkinManager.ApplyStylesOnApplication = false;
            }
        }

        /// <summary>
        /// Menu item click 
        /// </summary>
        /// <param name="item"></param>
        private void OnMenuItemClick(MenuItem item)
        {
            MenuItem parent = item.Parent as MenuItem;
            foreach (MenuItem menuItem in parent.Items)
            {
                menuItem.IsChecked = false;
            }
            item.IsChecked = true;
        }

        /// <summary>
        /// Set the active window
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
		private void OnActivateWindow(object sender, RoutedEventArgs e)
        {
            string name = (sender as MenuItem).Tag as string;
            DockingManager.ActivateWindow(name);
        }

        /// <summary>
        /// Initialize the windows forms host
        /// </summary>
        private void InitWindowsFormsHost()
        {
            if (DockingManager.UseInteropCompatibilityMode)
            {
                WindowsFormsHost host = new WindowsFormsHost();
                WinForms.Button btn = new WinForms.Button();
                btn.Text = "Winows Forms Button";
                host.Child = btn;
                // FindResults.Content = host;
                WindowsFormsHost.EnableWindowsFormsInterop();
            }
        }

        /// <summary>
        /// Ckear the events
        /// </summary>
        private void OnClear(object sender, EventArgs args)
        {
            Log.Text = "";
        }

        /// <summary>
        /// Events
        /// </summary>
        private void SubscribeForEvents()
        {
            //Subscribe the AutoHideAnimationStart property changed event
            DockingManager.AutoHideAnimationStart += new RoutedEventHandler(OnEventRaising);

            //Subscribe the AutoHideAnimationStop property changed event
            DockingManager.AutoHideAnimationStop += new RoutedEventHandler(OnEventRaising);

            //Subscribe the WindowActivated property changed event
            DockingManager.WindowActivated += new RoutedEventHandler(OnEventRaising);

            //Subscribe the WindowDeactivated property changed event
            DockingManager.WindowDeactivated += new RoutedEventHandler(OnEventRaising);

            //Subscribe the WindowDragStart property changed event
            DockingManager.WindowDragStart += new RoutedEventHandler(OnEventRaising);

            //Subscribe the WindowDragEnd property changed event
            DockingManager.WindowDragEnd += new RoutedEventHandler(OnEventRaising);

            //Subscribe the ActiveWindow property changed event
            DockingManager.ActiveWindowChanged += new PropertyChangedCallback(OnPropertyChanged);
        }

        #endregion

        #region Events
        /// <summary>
        /// Routed event raising
        /// </summary>
        private void OnEventRaising(object sender, RoutedEventArgs e)
        {
            FrameworkElement element = e.OriginalSource as FrameworkElement;
            string name = element != null ? element.Name : string.Empty;
            Log.TextWrapping = TextWrapping.Wrap;
            Log.Text = Log.Text + e.RoutedEvent.Name + " : " + name + "\n";
            Scroll.ScrollToBottom();

        }

        /// <summary>
        /// Property changed event raising
        /// </summary>
		private void OnPropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            string name = e.NewValue != null ? (e.NewValue as FrameworkElement).Name : string.Empty;
            Log.TextWrapping = TextWrapping.Wrap;
            Log.Text = Log.Text + e.Property.Name + " : " + name + "\n";
            Scroll.ScrollToBottom();
        }

        #endregion

        bool m_layoutflag = true;
        private void DockingManager_LayoutUpdated(object sender, EventArgs e)
        {
            if (m_layoutflag)
            {
                // SfSkinManager.SetVisualStyle(this, VisualStyles.Metro);
                m_layoutflag = false;
            }
        }

        /// <summary>
        /// Handles the CloseAllTabs event of the DockingManager control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="Syncfusion.Windows.Tools.Controls.CloseTabEventArgs"/> instance containing the event data.</param>
        private void DockingManager_CloseAllTabs(object sender, CloseTabEventArgs e)
        {
            string closingtabs = "";
            MessageBoxResult result = MessageBox.Show("Do you want to close the tabs? ", "Closing Tabs", MessageBoxButton.YesNo);
            if (result == MessageBoxResult.Yes)
            {
                for (int i = 0; i < e.ClosingTabItems.Count; i++)
                {
                    TabItemExt tabitem = e.ClosingTabItems[i] as TabItemExt;
                    if (tabitem.Content != null && (tabitem.Content as ContentPresenter) != null)
                    {
                        ContentPresenter presenter = tabitem.Content as ContentPresenter;
                        if (presenter != null && presenter.Content != null)
                        {
                            closingtabs = closingtabs + "\n\t" + DockingManager.GetHeader(presenter.Content as DependencyObject);
                        }
                    }
                }
                Log.TextWrapping = TextWrapping.Wrap;
                Log.Text = Log.Text + "Closed Tabs" + " : " + closingtabs + "\n";
                Scroll.ScrollToBottom();
            }
            else if (result == MessageBoxResult.No)
            {
                e.Cancel = true;
            }
        }

        /// <summary>
        /// Handles the CloseOtherTabs event of the DockingManager control.
        /// </summary>
        /// <param name="sender">The source of the event.</param>
        /// <param name="e">The <see cref="Syncfusion.Windows.Tools.Controls.CloseTabEventArgs"/> instance containing the event data.</param>
        private void DockingManager_CloseOtherTabs(object sender, CloseTabEventArgs e)
        {
            string closingtabs = "";
            MessageBoxResult result = MessageBox.Show("Do you want to close the tabs? ", "Closing Tabs", MessageBoxButton.YesNo);
            if (result == MessageBoxResult.Yes)
            {
                for (int i = 0; i < e.ClosingTabItems.Count; i++)
                {
                    TabItemExt tabitem = e.ClosingTabItems[i] as TabItemExt;
                    if (tabitem.Content != null && (tabitem.Content as ContentPresenter) != null)
                    {
                        ContentPresenter presenter = tabitem.Content as ContentPresenter;
                        if (presenter != null && presenter.Content != null)
                        {
                            closingtabs = closingtabs + "\n\t" + DockingManager.GetHeader(presenter.Content as DependencyObject);
                        }
                    }
                }
                Log.TextWrapping = TextWrapping.Wrap;
                Log.Text = Log.Text + "Closed Tabs" + " : " + closingtabs + "\n";
                Scroll.ScrollToBottom();
            }
            else if (result == MessageBoxResult.No)
            {
                e.Cancel = true;
            }
        }

        private void DockingManager_IsSelectedDocument(FrameworkElement sender, IsSelectedChangedEventArgs e)
        {
            if (DockingManager.DocContainer != null && SfSkinManager.GetVisualStyle(this) != SfSkinManager.GetVisualStyle(DockingManager.DocContainer as DependencyObject))
            {
                SfSkinManager.SetVisualStyle(DockingManager.DocContainer as DependencyObject, SfSkinManager.GetVisualStyle(this));
            }
        }


        private void btnRemoveSubmit_Clicked(object sender, RoutedEventArgs e)
        {
            if (fnamec != null && !fnamec.Equals(""))
            {


                var listBoxFrameId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[0];
                var listBoxMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[1];
                var listBoxMaskValue = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[2];
                if (listBoxMessage != null && listBoxMessage.HasItems && listBoxMessage.Items.Count > 0)
                {
                    int selectedIndex = listBoxMessage.SelectedIndex;
                    var ddMailBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[0];
                    var ddMailBoxMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[1];
                    string mailBox = (string)ddMailBox.SelectedItem;
                    string messg = (string)ddMailBoxMessage.SelectedItem;
                    if (messg != null && selectedIndex > -1)
                    {
                        if (messg.Equals("CANIF_TxBasicCANMailbox") && mailBoxMessageMore.ContainsKey(mailBox))
                        {
                            List<string> txMessages = mailBoxMessageMore[mailBox];
                            List<string> txFrameIds = mailBoxFrameIdMore[mailBox];
                            List<string> txMaskValue = mailBoxMaskValueMore[mailBox];
                            List<string> txMessageDLC = mailBoxDLCMore[mailBox];
                            if (txMessages != null && txMessages.Count > 0)
                            {
                                string removedMessage = txMessages[selectedIndex];
                                txMessages.RemoveAt(selectedIndex);
                                mailBoxMessageMore[mailBox] = txMessages;

                                txFrameIds.RemoveAt(selectedIndex);
                                txMaskValue.RemoveAt(selectedIndex);
                                txMessageDLC.RemoveAt(selectedIndex);

                                listBoxFrameId.Items.RemoveAt(selectedIndex);
                                listBoxMaskValue.Items.RemoveAt(selectedIndex);
                                listBoxMessage.Items.RemoveAt(selectedIndex);

                                mailBoxFrameIdMore[mailBox] = txFrameIds;
                                mailBoxMaskValueMore[mailBox] = txMaskValue;
                                mailBoxDLCMore[mailBox] = txMessageDLC;

                                if (listBoxMessage.Items != null && listBoxMessage.Items.Count > 0)
                                {
                                    for (int ind = 0; ind < listBoxMessage.Items.Count; ind++)
                                    {
                                        ComboBox ddMsg = (ComboBox)listBoxMessage.Items[ind];
                                        List<string> msgs = (List<string>)ddMsg.ItemsSource;
                                        msgs.Add(removedMessage);
                                        ComboBox ddMsgFrid = (ComboBox)listBoxFrameId.Items[ind];
                                        List<string> lMsgFrid = (List<string>)ddMsgFrid.ItemsSource;
                                        lMsgFrid.Add(messagesTxFrameIds[removedMessage]);
                                    }



                                }
                                else
                                {
                                    Button btnSubmitRemove = (sender as Button);
                                    btnSubmitRemove.IsEnabled = false;
                                }

                                var ddMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[4];
                                var ddMessageFrId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[3];
                                List<string> msgss = (List<string>)ddMessage.ItemsSource;
                                msgss.Add(removedMessage);

                                List<string> lMsgFrids = (List<string>)ddMessageFrId.ItemsSource;
                                lMsgFrids.Add(messagesTxFrameIds[removedMessage]);
                                ddMessageFrId.ItemsSource = null;
                                ddMessage.ItemsSource = null;


                                ddMessageFrId.ItemsSource = lMsgFrids;
                                ddMessage.ItemsSource = msgss;









                            }
                        }
                        else if (messg.Equals("CANIF_RxBasicCANMailbox") && mailBoxMessageMoreRx.ContainsKey(mailBox))
                        {

                            List<string> txMessages = mailBoxMessageMoreRx[mailBox];
                            List<string> txFrameIds = mailBoxFrameIdMoreRx[mailBox];
                            List<string> txMaskValue = mailBoxMaskValueMoreRx[mailBox];
                            List<string> txMessageDLC = mailBoxDLCMoreRx[mailBox];
                            if (txMessages != null && txMessages.Count > 0)
                            {
                                string removedMessage = txMessages[selectedIndex];
                                txMessages.RemoveAt(selectedIndex);
                                mailBoxMessageMoreRx[mailBox] = txMessages;

                                txFrameIds.RemoveAt(selectedIndex);
                                txMaskValue.RemoveAt(selectedIndex);
                                txMessageDLC.RemoveAt(selectedIndex);

                                listBoxFrameId.Items.RemoveAt(selectedIndex);
                                listBoxMaskValue.Items.RemoveAt(selectedIndex);
                                listBoxMessage.Items.RemoveAt(selectedIndex);

                                mailBoxFrameIdMoreRx[mailBox] = txFrameIds;
                                mailBoxMaskValueMoreRx[mailBox] = txMaskValue;
                                mailBoxDLCMoreRx[mailBox] = txMessageDLC;

                                if (listBoxMessage.Items != null && listBoxMessage.Items.Count > 0)
                                {
                                    for (int ind = 0; ind < listBoxMessage.Items.Count; ind++)
                                    {
                                        ComboBox ddMsg = (ComboBox)listBoxMessage.Items[ind];
                                        List<string> msgs = (List<string>)ddMsg.ItemsSource;
                                        msgs.Add(removedMessage);
                                        ComboBox ddMsgFrid = (ComboBox)listBoxFrameId.Items[ind];
                                        List<string> lMsgFrid = (List<string>)ddMsgFrid.ItemsSource;
                                        lMsgFrid.Add(messagesRxFrameIds[removedMessage]);
                                    }



                                }
                                else
                                {
                                    Button btnSubmitRemove = (sender as Button);
                                    btnSubmitRemove.IsEnabled = false;
                                }

                                var ddMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[4];
                                var ddMessageFrId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[3];
                                List<string> msgss = (List<string>)ddMessage.ItemsSource;
                                msgss.Add(removedMessage);
                                List<string> lMsgFrids = (List<string>)ddMessageFrId.ItemsSource;
                                lMsgFrids.Add(messagesRxFrameIds[removedMessage]);
                                ddMessageFrId.ItemsSource = null;
                                ddMessage.ItemsSource = null;
                                ddMessageFrId.ItemsSource = lMsgFrids;
                                ddMessage.ItemsSource = msgss;


                            }

                        }
                    }




                }
            }
        }

        
             private void btnRemoveSubmitHeder_Clicked(object sender, RoutedEventArgs e)
        {
            var listBoxHeader = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[3];
            int selectedIndex = listBoxHeader.SelectedIndex;
            if (listBoxHeader != null && selectedIndex > -1)
            {
                listBoxHeader.Items.RemoveAt(selectedIndex);
                headerFilsCanIf.RemoveAt(selectedIndex);

            }
        }
        private void btnRemoveSubmitHederM_Clicked(object sender, RoutedEventArgs e)
        {
            var listBoxHeader = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[0];
            int selectedIndex = listBoxHeader.SelectedIndex;
            if (listBoxHeader != null && selectedIndex > -1)
            {
                listBoxHeader.Items.RemoveAt(selectedIndex);
                headerFils.RemoveAt(selectedIndex);

            }
        }
        private void btnAddSubmitHeaderCanIf_Clicked(object sender, RoutedEventArgs e)
        {

            Button btnSubmit = (sender as Button);
            String lblbtnSubmitLbl = (String)btnSubmit.Content;
            var htextBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[4];
            headerFilsCanIf.Add(htextBox.Text);
           
            var htextListBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[3];
            htextListBox.Items.Add(htextBox.Text);
            htextBox.Text = "";

        }
        private void btnAddSubmitHeader_Clicked(object sender, RoutedEventArgs e)
        {

            Button btnSubmit = (sender as Button);
            String lblbtnSubmitLbl = (String)btnSubmit.Content;
            var htextBox = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[8];
            headerFils.Add(htextBox.Text);
            var htextListBox = SpForDynamicGridStaticCan.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[0];
            htextListBox.Items.Add(htextBox.Text);
            htextBox.Text = "";

        }
        private void btnAddSubmit_Clicked(object sender, RoutedEventArgs e)
        {
            if (fnamec != null && !fnamec.Equals(""))
            {
                Button btnSubmit = (sender as Button);
                String lblbtnSubmitLbl = (String)btnSubmit.Content;
                var drMailBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[0];
                var drCanIfMailBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[1];
                var drNetworkNode = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[2];
                var drMailFrameId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[3];
                var drMailMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[4];

                var txtDLC = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[0];
                var txtMaskValue = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[1];
                var btnAddMore = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<Button>().ToList()[0];
                var btnRemove = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<Button>().ToList()[2];
                string mailbox = (string)drMailBox.SelectedItem;
                string canifMailBox = (string)drCanIfMailBox.SelectedItem;
                string frameid = (string)drMailFrameId.SelectedItem;
                string message = (string)drMailMessage.SelectedItem;
                string txDLC = txtDLC.Text;
                string txMaskValue = txtMaskValue.Text;
                string node = (string)drNetworkNode.SelectedItem;

                if (lblbtnSubmitLbl.Equals("Edit/Update") && mailBoxCanif.ContainsKey(mailbox))
                {

                    //st
                    if (canifMailBox.Equals("CANIF_UnusedCANMailbox"))
                    {



                        String canIfMailBoxPrev = mailBoxCanif[mailbox];
                        if (canIfMailBoxPrev.Equals("CANIF_TxBasicCANMailbox"))
                        {

                            if (mailBoxMessageMore.ContainsKey(mailbox))
                            {
                                mailBoxMessageMore.Remove(mailbox);

                            }

                            if (mailBoxCanifNodeMore.ContainsKey(mailbox))
                            {

                                mailBoxCanifNodeMore.Remove(mailbox);


                            }
                            if (mailBoxFrameIdMore.ContainsKey(mailbox))
                            {

                                mailBoxFrameIdMore.Remove(mailbox);


                            }

                            if (mailBoxDLCMore.ContainsKey(mailbox))
                            {

                                mailBoxDLCMore.Remove(mailbox);


                            }

                            if (mailBoxMaskValueMore.ContainsKey(mailbox))
                            {
                                mailBoxMaskValueMore.Remove(mailbox);

                            }


                        }
                        else if (canIfMailBoxPrev.Equals("CANIF_RxBasicCANMailbox"))
                        {

                            if (mailBoxMessageMoreRx.ContainsKey(mailbox))
                            {
                                mailBoxMessageMoreRx.Remove(mailbox);

                            }

                            if (mailBoxCanifNodeMore.ContainsKey(mailbox))
                            {

                                mailBoxCanifNodeMore.Remove(mailbox);


                            }
                            if (mailBoxFrameIdMoreRx.ContainsKey(mailbox))
                            {

                                mailBoxFrameIdMoreRx.Remove(mailbox);


                            }

                            if (mailBoxDLCMoreRx.ContainsKey(mailbox))
                            {

                                mailBoxDLCMoreRx.Remove(mailbox);


                            }

                            if (mailBoxMaskValueMoreRx.ContainsKey(mailbox))
                            {
                                mailBoxMaskValueMoreRx.Remove(mailbox);

                            }


                        }
                        if (mailBoxCanif.ContainsKey(mailbox))
                        {

                            mailBoxCanif.Remove(mailbox);

                        }
                        if (mailBoxCanifNode.ContainsKey(mailbox))
                        {

                            mailBoxCanifNode.Remove(mailbox);


                        }

                        if (mailBoxMessage.ContainsKey(mailbox))
                        {
                            mailBoxMessage.Remove(mailbox);

                        }

                        if (mailBoxMessageRx.ContainsKey(mailbox))
                        {
                            mailBoxMessageRx.Remove(mailbox);

                        }

                        if (mailBoxFrameId.ContainsKey(mailbox))
                        {

                            mailBoxFrameId.Remove(mailbox);


                        }
                        if (mailBoxFrameIdRx.ContainsKey(mailbox))
                        {

                            mailBoxFrameIdRx.Remove(mailbox);


                        }

                        if (mailBoxDLC.ContainsKey(mailbox))
                        {

                            mailBoxDLC.Remove(mailbox);


                        }
                        if (mailBoxDLCRx.ContainsKey(mailbox))
                        {

                            mailBoxDLCRx.Remove(mailbox);


                        }

                        if (mailBoxMaskValue.ContainsKey(mailbox))
                        {
                            mailBoxMaskValue.Remove(mailbox);

                        }
                        if (mailBoxMaskValueRx.ContainsKey(mailbox))
                        {
                            mailBoxMaskValueRx.Remove(mailbox);

                        }

                        //end
                        MessageBox.Show("Successfully Updated");
                        return;
                    }
                }
                bool isHexa = System.Text.RegularExpressions.Regex.IsMatch(txMaskValue, @"\A\b(0[xX][0-9a-fA-F]{1,4})+\b\Z");
                if (lblbtnSubmitLbl.Equals("Submit"))
                {
                    if (!isHexa)
                    {
                        MessageBox.Show("provide  values in hexa decimal format");
                        return;
                    }

                }

                //if (frameid != null && !frameid.Trim().Equals("") && message != null && !message.Trim().Equals("") && txDLC != null && !txDLC.Trim().Equals("") && txMaskValue != null && !txMaskValue.Trim().Equals(""))
                if (frameid != null && !frameid.Trim().Equals("") && message != null && !message.Trim().Equals("") && txDLC != null && !txDLC.Trim().Equals(""))
                {

                    if (lblbtnSubmitLbl.Equals("Submit"))
                    {
                        if (canifMailBox.Equals("CANIF_RxBasicCANMailbox") || canifMailBox.Equals("CANIF_RxFullCANMailbox"))
                        {

                            if (canifMailBox.Equals("CANIF_RxBasicCANMailbox"))
                            {

                                mailBoxCanif[mailbox] = canifMailBox;
                                mailBoxCanifNode[mailbox] = node;
                                btnAddMoreButton_Clicked(sender, e);

                                btnAddMore.IsEnabled = true;
                            }
                            else
                            {
                                mailBoxCanif[mailbox] = canifMailBox;
                                mailBoxCanifNode[mailbox] = node;
                                mailBoxFrameIdRx[mailbox] = frameid;
                                mailBoxMessageRx[mailbox] = message;
                                mailBoxDLCRx[mailbox] = txDLC;
                                mailBoxMaskValueRx[mailbox] = txMaskValue;
                                btnAddMore.IsEnabled = false;
                                MessageBox.Show("Successfully Submited");
                            }


                        }
                        else if (canifMailBox.Equals("CANIF_TxBasicCANMailbox") || canifMailBox.Equals("CANIF_TxFullCANMailbox"))
                        {



                            if (canifMailBox.Equals("CANIF_TxBasicCANMailbox"))
                            {

                                btnAddMore.IsEnabled = true;
                                mailBoxCanif[mailbox] = canifMailBox;
                                mailBoxCanifNode[mailbox] = node;
                                btnAddMoreButton_Clicked(sender, e);
                            }
                            else
                            {
                                btnAddMore.IsEnabled = false;
                                mailBoxCanif[mailbox] = canifMailBox;
                                mailBoxCanifNode[mailbox] = node;
                                mailBoxFrameId[mailbox] = frameid;
                                mailBoxMessage[mailbox] = message;
                                mailBoxDLC[mailbox] = txDLC;
                                mailBoxMaskValue[mailbox] = txMaskValue;
                                MessageBox.Show("Successfully Submited");
                            }
                        }
                        btnSubmit.IsEnabled = true;
                        btnSubmit.Content = "Edit/Update";


                    }
                    else if (lblbtnSubmitLbl.Equals("Edit/Update") && mailBoxCanif.ContainsKey(mailbox))
                    {
                        btnAddMore.IsEnabled = false;
                        //st
                        if (canifMailBox.Equals("CANIF_TxFullCANMailbox") || canifMailBox.Equals("CANIF_RxFullCANMailbox"))
                        {
                            if (!isHexa)
                            {
                                MessageBox.Show("provide  values in hexa decimal format");
                                return;
                            }

                        }

                        String canIfMailBoxPrev = mailBoxCanif[mailbox];

                        if (canIfMailBoxPrev.Equals("CANIF_TxBasicCANMailbox") && !canifMailBox.Equals("CANIF_TxBasicCANMailbox"))
                        {
                            if (mailBoxCanif.ContainsKey(mailbox))
                            {
                                mailBoxCanif.Remove(mailbox);
                            }
                            if (mailBoxCanifNode.ContainsKey(mailbox))
                            {
                                mailBoxCanifNode.Remove(mailbox);
                            }

                            if (mailBoxFrameId.ContainsKey(mailbox))
                            {
                                mailBoxFrameId.Remove(mailbox);
                            }

                            if (mailBoxMessage.ContainsKey(mailbox))
                            {
                                mailBoxMessage.Remove(mailbox);
                            }
                            if (mailBoxDLC.ContainsKey(mailbox))
                            {
                                mailBoxDLC.Remove(mailbox);
                            }
                            if (mailBoxMaskValue.ContainsKey(mailbox))
                            {
                                mailBoxMaskValue.Remove(mailbox);
                            }

                            if (mailBoxMessageMore.ContainsKey(mailbox))
                            {
                                mailBoxMessageMore.Remove(mailbox);

                            }

                            if (mailBoxCanifNodeMore.ContainsKey(mailbox))
                            {

                                mailBoxCanifNodeMore.Remove(mailbox);


                            }
                            if (mailBoxFrameIdMore.ContainsKey(mailbox))
                            {

                                mailBoxFrameIdMore.Remove(mailbox);


                            }

                            if (mailBoxDLCMore.ContainsKey(mailbox))
                            {

                                mailBoxDLCMore.Remove(mailbox);


                            }

                            if (mailBoxMaskValueMore.ContainsKey(mailbox))
                            {
                                mailBoxMaskValueMore.Remove(mailbox);

                            }


                        }
                        else if (canIfMailBoxPrev.Equals("CANIF_RxBasicCANMailbox") && !canifMailBox.Equals("CANIF_RxBasicCANMailbox"))
                        {

                            if (mailBoxCanif.ContainsKey(mailbox))
                            {
                                mailBoxCanif.Remove(mailbox);
                            }
                            if (mailBoxCanifNode.ContainsKey(mailbox))
                            {
                                mailBoxCanifNode.Remove(mailbox);
                            }

                            if (mailBoxFrameIdRx.ContainsKey(mailbox))
                            {
                                mailBoxFrameIdRx.Remove(mailbox);
                            }

                            if (mailBoxMessageRx.ContainsKey(mailbox))
                            {
                                mailBoxMessageRx.Remove(mailbox);
                            }
                            if (mailBoxDLCRx.ContainsKey(mailbox))
                            {
                                mailBoxDLCRx.Remove(mailbox);
                            }
                            if (mailBoxMaskValueRx.ContainsKey(mailbox))
                            {
                                mailBoxMaskValueRx.Remove(mailbox);
                            }

                            if (mailBoxMessageMoreRx.ContainsKey(mailbox))
                            {
                                mailBoxMessageMoreRx.Remove(mailbox);

                            }

                            if (mailBoxCanifNodeMore.ContainsKey(mailbox))
                            {

                                mailBoxCanifNodeMore.Remove(mailbox);


                            }
                            if (mailBoxFrameIdMoreRx.ContainsKey(mailbox))
                            {

                                mailBoxFrameIdMoreRx.Remove(mailbox);


                            }

                            if (mailBoxDLCMoreRx.ContainsKey(mailbox))
                            {

                                mailBoxDLCMoreRx.Remove(mailbox);


                            }

                            if (mailBoxMaskValueMoreRx.ContainsKey(mailbox))
                            {
                                mailBoxMaskValueMoreRx.Remove(mailbox);

                            }


                        }
                        if (canifMailBox.Equals("CANIF_RxBasicCANMailbox") || canifMailBox.Equals("CANIF_RxFullCANMailbox"))
                        {


                            if (canifMailBox.Equals("CANIF_RxBasicCANMailbox"))
                            {
                                if (!mailBoxMessageMoreRx.ContainsKey(mailbox))
                                {

                                    if (!isHexa)
                                    {
                                        MessageBox.Show("provide  values in hexa decimal format");
                                        return;
                                    }
                                    mailBoxCanif[mailbox] = canifMailBox;
                                    mailBoxCanifNode[mailbox] = (string)drNetworkNode.SelectedItem;
                                    btnAddMoreButton_Clicked(sender, e);

                                    btnAddMore.IsEnabled = true;
                                }
                                else
                                {
                                    mailBoxCanif[mailbox] = canifMailBox;
                                    mailBoxCanifNode[mailbox] = node;
                                    var listBoxFrameId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[0];
                                    var listBoxMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[1];
                                    var listBoxMessageMaskValue = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[2];

                                    if (listBoxFrameId != null && listBoxFrameId.Items != null && listBoxFrameId.Items.Count > 0)
                                    {
                                        List<string> lstFids = mailBoxFrameIdMoreRx[mailbox];
                                        List<string> lstMsgs = mailBoxMessageMoreRx[mailbox];
                                        List<string> lstDLcs = mailBoxDLCMoreRx[mailbox];
                                        List<string> lstMaskValues = mailBoxMaskValueMoreRx[mailbox];

                                        for (int inx = 0; inx < listBoxFrameId.Items.Count; inx++)
                                        {
                                            ComboBox cfid = (ComboBox)listBoxFrameId.Items[inx];
                                            ComboBox cmsg = (ComboBox)listBoxMessage.Items[inx];
                                            TextBox tmv = (TextBox)listBoxMessageMaskValue.Items[inx];
                                            lstFids[inx] = cfid.SelectedItem.ToString();
                                            lstMsgs[inx] = cmsg.SelectedItem.ToString();
                                            lstMaskValues[inx] = tmv.Text;
                                            lstDLcs[inx] = messagesRxDLC[cmsg.SelectedItem.ToString()];


                                        }
                                    }

                                    btnAddMore.IsEnabled = true;
                                }

                            }
                            else
                            {
                                mailBoxCanif[mailbox] = canifMailBox;
                                mailBoxCanifNode[mailbox] = node;
                                mailBoxFrameIdRx[mailbox] = frameid;
                                mailBoxMessageRx[mailbox] = message;
                                mailBoxDLCRx[mailbox] = txDLC;
                                mailBoxMaskValueRx[mailbox] = txMaskValue;
                                btnAddMore.IsEnabled = false;
                            }


                        }
                        else if (canifMailBox.Equals("CANIF_TxBasicCANMailbox") || canifMailBox.Equals("CANIF_TxFullCANMailbox"))
                        {


                            if (canifMailBox.Equals("CANIF_TxBasicCANMailbox"))
                            {
                                if (!mailBoxMessageMore.ContainsKey(mailbox))
                                {
                                    if (!isHexa)
                                    {
                                        MessageBox.Show("provide  values in hexa decimal format");
                                        return;
                                    }
                                    mailBoxCanif[mailbox] = canifMailBox;
                                    mailBoxCanifNode[mailbox] = (string)drNetworkNode.SelectedItem;
                                    btnAddMoreButton_Clicked(sender, e);

                                    btnAddMore.IsEnabled = true;
                                }
                                else
                                {
                                    mailBoxCanif[mailbox] = canifMailBox;
                                    mailBoxCanifNode[mailbox] = node;
                                    var listBoxFrameId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[0];
                                    var listBoxMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[1];
                                    var listBoxMessageMaskValue = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[2];

                                    if (listBoxFrameId != null && listBoxFrameId.Items != null && listBoxFrameId.Items.Count > 0)
                                    {
                                        List<string> lstFids = mailBoxFrameIdMore[mailbox];
                                        List<string> lstMsgs = mailBoxMessageMore[mailbox];
                                        List<string> lstDLcs = mailBoxDLCMore[mailbox];
                                        List<string> lstMaskValues = mailBoxMaskValueMore[mailbox];

                                        for (int inx = 0; inx < listBoxFrameId.Items.Count; inx++)
                                        {
                                            ComboBox cfid = (ComboBox)listBoxFrameId.Items[inx];
                                            ComboBox cmsg = (ComboBox)listBoxMessage.Items[inx];
                                            TextBox tmv = (TextBox)listBoxMessageMaskValue.Items[inx];
                                            lstFids[inx] = cfid.SelectedItem.ToString();
                                            lstMsgs[inx] = cmsg.SelectedItem.ToString();
                                            lstMaskValues[inx] = tmv.Text;
                                            lstDLcs[inx] = messagesTxDLC[cmsg.SelectedItem.ToString()];


                                        }
                                    }

                                    btnAddMore.IsEnabled = true;

                                }

                            }
                            else
                            {
                                mailBoxCanif[mailbox] = canifMailBox;
                                mailBoxCanifNode[mailbox] = node;
                                mailBoxFrameId[mailbox] = frameid;
                                mailBoxMessage[mailbox] = message;
                                mailBoxDLC[mailbox] = txDLC;
                                mailBoxMaskValue[mailbox] = txMaskValue;

                                btnAddMore.IsEnabled = false;
                            }
                        }
                        //end
                        MessageBox.Show("Successfully Updated");

                    }

                }
            }






        }

        private void btnAddMoreButton_Clicked(object sender, RoutedEventArgs e)
        {

            if (fnamec != null && !fnamec.Trim().Equals(""))
            {

                var drMailBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[0];
                var drCanIfMailBox = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[1];
                var drCanIfMailBoxNode = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[2];
                var drFrameId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[3];
                var drMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ComboBox>().ToList()[4];
                var txtDLC = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[0];
                var txtMask = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<TextBox>().ToList()[1];

                string mailbox = (string)drMailBox.SelectedItem;
                string canifMailBox = (string)drCanIfMailBox.SelectedItem;
                string frameid = (string)drFrameId.SelectedItem;
                string message = (string)drMessage.SelectedItem;
                string txDLC = txtDLC.Text;
                string txMask = txtMask.Text;
                string node = (string)drCanIfMailBoxNode.SelectedItem;
                bool isHexa = System.Text.RegularExpressions.Regex.IsMatch(txMask, @"\A\b(0[xX][0-9a-fA-F]{1,4})+\b\Z");

                if (!isHexa)
                {
                    MessageBox.Show("provide  values in hexa decimal format");
                    return;
                }
                if (txMask != null && !txMask.Trim().Equals("") && txDLC != null && !txDLC.Trim().Equals("") && message != null && !message.Trim().Equals("") && frameid != null && !frameid.Trim().Equals("") && canifMailBox != null && !canifMailBox.Trim().Equals("") && mailbox != null && !mailbox.Trim().Equals(""))
                {

                    if (canifMailBox.Equals("CANIF_TxBasicCANMailbox"))
                    {
                        if (mailBoxMessageMore.ContainsKey(mailbox))
                        {
                            List<string> lstMessage = mailBoxMessageMore[mailbox];
                            lstMessage.Add(message);
                            mailBoxMessageMore[mailbox] = lstMessage;
                            List<string> lstFameId = mailBoxFrameIdMore[mailbox];
                            lstFameId.Add(frameid);
                            mailBoxFrameIdMore[mailbox] = lstFameId;
                            List<string> lstDLC = mailBoxDLCMore[mailbox];
                            lstDLC.Add(txDLC);
                            mailBoxDLCMore[mailbox] = lstDLC;
                            List<string> lstMaskValue = mailBoxMaskValueMore[mailbox];
                            lstMaskValue.Add(txMask);
                            mailBoxMaskValueMore[mailbox] = lstMaskValue;
                            List<string> lstNode = mailBoxCanifNodeMore[mailbox];
                            lstNode.Add(node);
                            mailBoxCanifNodeMore[mailbox] = lstNode;
                        }
                        else
                        {
                            List<string> lstMessage = new List<string>();
                            lstMessage.Add(message);
                            mailBoxMessageMore[mailbox] = lstMessage;
                            List<string> lstFameId = new List<string>();
                            lstFameId.Add(frameid);
                            mailBoxFrameIdMore[mailbox] = lstFameId;
                            List<string> lstDLC = new List<string>();
                            lstDLC.Add(txDLC);
                            mailBoxDLCMore[mailbox] = lstDLC;
                            List<string> lstMaskValue = new List<string>();
                            lstMaskValue.Add(txMask);
                            mailBoxMaskValueMore[mailbox] = lstMaskValue;
                            List<string> lstNode = new List<string>();
                            lstNode.Add(node);
                            mailBoxCanifNodeMore[mailbox] = lstNode;
                        }
                        //start
                        if (true)
                        {
                            List<string> onlyTxMessageAlloted = new List<string>();
                            List<string> onlyTxMessageFrameIdAlloted = new List<string>();
                            foreach (KeyValuePair<string, string> kvp in mailBoxMessage)
                            {
                                onlyTxMessageAlloted.Add(kvp.Value);
                                onlyTxMessageFrameIdAlloted.Add(messagesTxFrameIds[kvp.Value]);

                            }
                            foreach (KeyValuePair<string, List<String>> kvp in mailBoxMessageMore)
                            {
                                List<String> ls = kvp.Value;
                                if (ls != null)
                                {
                                    foreach (String s in ls)
                                    {
                                        onlyTxMessageAlloted.Add(s);
                                        onlyTxMessageFrameIdAlloted.Add(messagesTxFrameIds[s]);
                                    }
                                }

                            }
                            List<string> txMessagesRemaing = new List<string>();
                            List<string> txMessagesFrameIdRemaing = new List<string>();
                            List<string> allTxMessagesNode = txMessage.ContainsKey(node) ? txMessage[node] : null;
                            if (allTxMessagesNode != null && allTxMessagesNode.Count > 0)
                            {
                                foreach (string msg in allTxMessagesNode)
                                {
                                    if (!onlyTxMessageAlloted.Contains(msg))
                                    {
                                        txMessagesRemaing.Add(msg);
                                        txMessagesFrameIdRemaing.Add(messagesTxFrameIds[msg]);
                                    }
                                }
                            }
                            drMessage.ItemsSource = txMessagesRemaing;
                            drFrameId.ItemsSource = txMessagesFrameIdRemaing;

                            //s1
                            var listBoxFrameId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[0];
                            var listBoxMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[1];
                            var listBoxMessageMaskValue = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[2];

                            listBoxFrameId.Items.Clear();
                            listBoxMessage.Items.Clear();
                            listBoxMessageMaskValue.Items.Clear();

                            //start

                            if (mailBoxMessageMore.ContainsKey(selectedMailBox))
                            {
                                List<string> txMoreMessagesFrameids = mailBoxFrameIdMore[selectedMailBox];
                                List<string> txMoreMessages = mailBoxMessageMore[selectedMailBox];
                                if (txMoreMessagesFrameids != null && txMoreMessagesFrameids.Count > 0)
                                {
                                    var btnRemove = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<Button>().ToList()[2];
                                    btnRemove.IsEnabled = true;
                                    for (int ind = 0; ind < txMoreMessagesFrameids.Count; ind++)
                                    {

                                        ComboBox drpDwnMailRxFrameIdBox = new ComboBox();
                                        drpDwnMailRxFrameIdBox.Name = "MailFrame" + ind + "_Val";
                                        drpDwnMailRxFrameIdBox.FontSize = 12;
                                        drpDwnMailRxFrameIdBox.FontWeight = FontWeights.Bold;
                                        drpDwnMailRxFrameIdBox.Height = 30;
                                        drpDwnMailRxFrameIdBox.Width = 280;
                                        drpDwnMailRxFrameIdBox.Background = Brushes.White;
                                        drpDwnMailRxFrameIdBox.IsSynchronizedWithCurrentItem = true;
                                        drpDwnMailRxFrameIdBox.SelectionChanged += drpDwnMailTxFrameIdBoxs_SelectionChanged;

                                        ComboBox drpDwnMailRxMessageBox = new ComboBox();
                                        drpDwnMailRxMessageBox.Name = "MailMessage" + ind + "_Val";
                                        drpDwnMailRxMessageBox.FontSize = 12;
                                        drpDwnMailRxMessageBox.FontWeight = FontWeights.Bold;
                                        drpDwnMailRxMessageBox.Height = 30;
                                        drpDwnMailRxMessageBox.Width = 280;
                                        drpDwnMailRxMessageBox.Background = Brushes.White;
                                        drpDwnMailRxMessageBox.IsSynchronizedWithCurrentItem = true;
                                        drpDwnMailRxMessageBox.SelectionChanged += drpDwnMailTxMessageBoxs_SelectionChanged; ;
                                        List<string> txMsgsFrameid = new List<string>();
                                        txMsgsFrameid.Add(txMoreMessagesFrameids[ind]);
                                        List<string> txMsgs = new List<string>();
                                        txMsgs.Add(txMoreMessages[ind]);
                                        foreach (string frid in txMessagesFrameIdRemaing)
                                        {
                                            txMsgsFrameid.Add(frid);
                                        }
                                        foreach (string txm in txMessagesRemaing)
                                        {
                                            txMsgs.Add(txm);
                                        }
                                        drpDwnMailRxFrameIdBox.ItemsSource = txMsgsFrameid;
                                        drpDwnMailRxMessageBox.ItemsSource = txMsgs;

                                        TextBox txtBoxMaskValue = new TextBox();
                                        txtBoxMaskValue.Text = mailBoxMaskValueMore[selectedMailBox][ind];
                                        txtBoxMaskValue.FontSize = 12;
                                        txtBoxMaskValue.FontWeight = FontWeights.Bold;
                                        txtBoxMaskValue.Height = 30;
                                        txtBoxMaskValue.Background = Brushes.White;
                                        txtBoxMaskValue.IsEnabled = true;
                                        txtBoxMaskValue.Width = 280;

                                        txtBoxMaskValue.Name = "txtMask" + ind + "_Val";

                                        listBoxFrameId.Items.Add(drpDwnMailRxFrameIdBox);
                                        listBoxMessage.Items.Add(drpDwnMailRxMessageBox);
                                        listBoxMessageMaskValue.Items.Add(txtBoxMaskValue);

                                    }

                                }
                            }
                            //end

                            //e1
                        }
                        //end




                    }
                    else if (canifMailBox.Equals("CANIF_RxBasicCANMailbox"))
                    {



                        if (mailBoxMessageMoreRx.ContainsKey(mailbox))
                        {
                            List<string> lstMessage = mailBoxMessageMoreRx[mailbox];
                            lstMessage.Add(message);
                            mailBoxMessageMoreRx[mailbox] = lstMessage;
                            List<string> lstFameId = mailBoxFrameIdMoreRx[mailbox];
                            lstFameId.Add(frameid);
                            mailBoxFrameIdMoreRx[mailbox] = lstFameId;
                            List<string> lstDLC = mailBoxDLCMoreRx[mailbox];
                            lstDLC.Add(txDLC);
                            mailBoxDLCMoreRx[mailbox] = lstDLC;
                            List<string> lstMaskValue = mailBoxMaskValueMoreRx[mailbox];
                            lstMaskValue.Add(txMask);
                            mailBoxMaskValueMoreRx[mailbox] = lstMaskValue;
                            List<string> lstNode = mailBoxCanifNodeMore[mailbox];
                            lstNode.Add(node);
                            mailBoxCanifNodeMore[mailbox] = lstNode;

                        }
                        else
                        {
                            List<string> lstMessage = new List<string>();
                            lstMessage.Add(message);
                            mailBoxMessageMoreRx[mailbox] = lstMessage;
                            List<string> lstFameId = new List<string>();
                            lstFameId.Add(frameid);
                            mailBoxFrameIdMoreRx[mailbox] = lstFameId;
                            List<string> lstDLC = new List<string>();
                            lstDLC.Add(txDLC);
                            mailBoxDLCMoreRx[mailbox] = lstDLC;
                            List<string> lstMaskValue = new List<string>();
                            lstMaskValue.Add(txMask);
                            mailBoxMaskValueMoreRx[mailbox] = lstMaskValue;
                            List<string> lstNode = new List<string>();
                            lstNode.Add(node);
                            mailBoxCanifNodeMore[mailbox] = lstNode;
                        }
                        //start
                        if (true)
                        {
                            List<string> onlyRxMessageAlloted = new List<string>();
                            List<string> onlyRxMessageFrameIdAlloted = new List<string>();
                            foreach (KeyValuePair<string, string> kvp in mailBoxMessageRx)
                            {
                                onlyRxMessageAlloted.Add(kvp.Value);
                                onlyRxMessageFrameIdAlloted.Add(messagesRxFrameIds[kvp.Value]);

                            }
                            foreach (KeyValuePair<string, List<String>> kvp in mailBoxMessageMoreRx)
                            {
                                List<String> ls = kvp.Value;
                                if (ls != null)
                                {
                                    foreach (String s in ls)
                                    {
                                        onlyRxMessageAlloted.Add(s);
                                        onlyRxMessageFrameIdAlloted.Add(messagesRxFrameIds[s]);
                                    }
                                }

                            }
                            List<string> rxMessagesRemaing = new List<string>();
                            List<string> rxMessagesFrameIdRemaing = new List<string>();
                            List<string> allRxMessagesNode = rxMessage.ContainsKey(node) ? rxMessage[node] : null;
                            if (allRxMessagesNode != null && allRxMessagesNode.Count > 0)
                            {
                                foreach (string msg in allRxMessagesNode)
                                {
                                    if (!onlyRxMessageAlloted.Contains(msg))
                                    {
                                        rxMessagesRemaing.Add(msg);
                                        rxMessagesFrameIdRemaing.Add(messagesRxFrameIds[msg]);
                                    }
                                }
                            }
                            drMessage.ItemsSource = rxMessagesRemaing;
                            drFrameId.ItemsSource = rxMessagesFrameIdRemaing;
                            //s1
                            var listBoxFrameId = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[0];
                            var listBoxMessage = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[1];
                            var listBoxMessageMaskValue = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<ListBox>().ToList()[2];

                            listBoxFrameId.Items.Clear();
                            listBoxMessage.Items.Clear();
                            listBoxMessageMaskValue.Items.Clear();

                            //start

                            if (mailBoxMessageMoreRx.ContainsKey(selectedMailBox))
                            {
                                List<string> txMoreMessagesFrameids = mailBoxFrameIdMoreRx[selectedMailBox];
                                List<string> txMoreMessages = mailBoxMessageMoreRx[selectedMailBox];
                                if (txMoreMessagesFrameids != null && txMoreMessagesFrameids.Count > 0)
                                {
                                    var btnRemove = SpForDynamicGridIf.Children.OfType<Grid>().ToList()[0].Children.OfType<Button>().ToList()[2];
                                    btnRemove.IsEnabled = true;
                                    for (int ind = 0; ind < txMoreMessagesFrameids.Count; ind++)
                                    {

                                        ComboBox drpDwnMailRxFrameIdBox = new ComboBox();
                                        drpDwnMailRxFrameIdBox.Name = "MailFrame" + ind + "_Val";
                                        drpDwnMailRxFrameIdBox.FontSize = 12;
                                        drpDwnMailRxFrameIdBox.FontWeight = FontWeights.Bold;
                                        drpDwnMailRxFrameIdBox.Height = 30;
                                        drpDwnMailRxFrameIdBox.Width = 280;
                                        drpDwnMailRxFrameIdBox.Background = Brushes.White;
                                        drpDwnMailRxFrameIdBox.IsSynchronizedWithCurrentItem = true;
                                        drpDwnMailRxFrameIdBox.SelectionChanged += drpDwnMailTxFrameIdBoxs_SelectionChanged;

                                        ComboBox drpDwnMailRxMessageBox = new ComboBox();
                                        drpDwnMailRxMessageBox.Name = "MailMessage" + ind + "_Val";
                                        drpDwnMailRxMessageBox.FontSize = 12;
                                        drpDwnMailRxMessageBox.FontWeight = FontWeights.Bold;
                                        drpDwnMailRxMessageBox.Height = 30;
                                        drpDwnMailRxMessageBox.Width = 280;
                                        drpDwnMailRxMessageBox.Background = Brushes.White;
                                        drpDwnMailRxMessageBox.IsSynchronizedWithCurrentItem = true;
                                        drpDwnMailRxMessageBox.SelectionChanged += drpDwnMailTxMessageBoxs_SelectionChanged; ;
                                        List<string> txMsgsFrameid = new List<string>();
                                        txMsgsFrameid.Add(txMoreMessagesFrameids[ind]);
                                        List<string> txMsgs = new List<string>();
                                        txMsgs.Add(txMoreMessages[ind]);
                                        foreach (string frid in rxMessagesFrameIdRemaing)
                                        {
                                            txMsgsFrameid.Add(frid);
                                        }
                                        foreach (string txm in rxMessagesRemaing)
                                        {
                                            txMsgs.Add(txm);
                                        }
                                        drpDwnMailRxFrameIdBox.ItemsSource = txMsgsFrameid;
                                        drpDwnMailRxMessageBox.ItemsSource = txMsgs;

                                        TextBox txtBoxMaskValue = new TextBox();
                                        txtBoxMaskValue.Text = mailBoxMaskValueMoreRx[selectedMailBox][ind];
                                        txtBoxMaskValue.FontSize = 12;
                                        txtBoxMaskValue.FontWeight = FontWeights.Bold;
                                        txtBoxMaskValue.Height = 30;
                                        txtBoxMaskValue.Background = Brushes.White;
                                        txtBoxMaskValue.IsEnabled = true;
                                        txtBoxMaskValue.Width = 280;

                                        txtBoxMaskValue.Name = "txtMask" + ind + "_Val";

                                        listBoxFrameId.Items.Add(drpDwnMailRxFrameIdBox);
                                        listBoxMessage.Items.Add(drpDwnMailRxMessageBox);
                                        listBoxMessageMaskValue.Items.Add(txtBoxMaskValue);

                                    }

                                }
                            }
                            //end

                            //e1
                        }
                        //end

                    }
                    MessageBox.Show("Successfully Submited");
                    btnAddMore.IsEnabled = true;

                }
                else
                {
                    MessageBox.Show("select frameid");
                }
            }
        }


        private void OpenBtn_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            Serializer ser = new Serializer();
            string stringFile = string.Empty;
            string FileExt = string.Empty;
            string DirPath = string.Empty;

            if (Directory.GetCurrentDirectory().Contains("bin"))
            {
                DirPath = Directory.GetCurrentDirectory().Substring(0, Directory.GetCurrentDirectory().IndexOf("\\bin"));
            }
            else
            {
                DirPath = Directory.GetCurrentDirectory();
            }

            if (openFileDialog.ShowDialog() == true)
            {
                stringFile = File.ReadAllText(openFileDialog.FileName);
                FileExt = Path.GetExtension(openFileDialog.FileName);
            }
            if (FileExt.Equals(".arxml", StringComparison.OrdinalIgnoreCase))
            {
                try
                {
                    DockingManagerModelHelper.Configuration = ser.Deserialize<AUTOSAR>(stringFile);
                    DockingManagerModelHelper.ProjectName = DockingManagerModelHelper.Configuration.ARPACKAGES[0].ELEMENTS.ECUCMODULECONFIGURATIONVALUES.DEFINITIONREF.Value;
                    File.WriteAllText(DockingManagerModelHelper.TargetInputFolderPath + "\\DefaultConfig.arxml", stringFile);
                    PopulateWorkspaceExplorer();
                    CreateDynamicWPFGridForModule();

                    MessageBox.Show(openFileDialog.FileName + " Loaded Successfully.");
                }
                catch (Exception)
                {
                    MessageBox.Show("Invalid ARXML format....Please select an ARXML file with defined format.");
                }
            }
            else if (FileExt.Equals(".dbc", StringComparison.OrdinalIgnoreCase))
            {
                File.WriteAllText(DockingManagerModelHelper.TargetInputFolderPath + "\\Sample_DB.dbc", stringFile);
                MessageBox.Show(openFileDialog.FileName + " Loaded Successfully.");
            }
            else if (FileExt.Equals(".h", StringComparison.OrdinalIgnoreCase))
            {
                File.WriteAllText(DockingManagerModelHelper.TargetInputFolderPath + "\\CAN_Driver_cfg.h", stringFile);
                MessageBox.Show(openFileDialog.FileName + " Loaded Successfully.");
            }
            else
            {
                MessageBox.Show("Only files having extension .ARXML, .DBC and .h files can be opened.");
            }
        }

        private void GenerateCanMgrBtn_Click(object sender, RoutedEventArgs e)
        {
            String Message = "Output Files Generated and Saved Successfully at following path : " + DockingManagerModelHelper.TargetOutputFolderPath;
            if (isManual)
            {
                rxmReceptionTimeout = rxReceptionTimeout;
            }
            else
            {
                rxmReceptionTimeout = rxReceptionTimeoutDefault;
            }

            if (fnamec.LastIndexOf("(") > 0)
            {
                genCFile(fnamec.Substring(0, fnamec.LastIndexOf("(")).Replace(".", "_").Trim());
            }
            else
            {
                genCFile(fnamec.Replace(".", "_").Trim());
            }
            genHeaderFile();

            MessageBox.Show(Message);


        }
        private void genCFile(String fname)
        {
            using (StreamWriter outputFile = new StreamWriter(Path.Combine(DockingManagerModelHelper.TargetOutputFolderPath, "CanMgr_cfg.c")))
            {
                outputFile.WriteLine("/*");
                outputFile.WriteLine("* CanMgr_cfg.c");
                outputFile.WriteLine("*");
                outputFile.WriteLine("*  Created on:" + DateTime.Now.ToString("d-M-yyyy"));
                outputFile.WriteLine("*      Author: " + Environment.MachineName);
                outputFile.WriteLine("*/");
                outputFile.WriteLine("");
                outputFile.WriteLine("/*********************************************************************************************************************** ");
                outputFile.WriteLine("  *    DISCLAIMER                                                                                                        ");
                outputFile.WriteLine("  *    Copyright (C) 2011, 2016 Niyata Infotech Ptv. Ltd. All rights reserved.                                              ");
                outputFile.WriteLine("  ***********************************************************************************************************************/");
                outputFile.WriteLine("");
                outputFile.WriteLine("/***********************************************************************************************************************");
                outputFile.WriteLine("  * @author              Author : Mahendran L (mahendranl@niyatainfotech.com)                                                                         ");
                outputFile.WriteLine("***********************************************************************************************************************/");
                outputFile.WriteLine("/***********************************************************************************************************************");
                outputFile.WriteLine("  *                                                F I L E  D E S C R I P T I O N                                           ");
                outputFile.WriteLine("  *---------------------------------------------------------------------------------------------------------------------");
                outputFile.WriteLine("*  @brief                                                                                                             ");
                outputFile.WriteLine(" * ");
                outputFile.WriteLine("*  File name                       : CanMgr_cfg.c                                                                         ");
                outputFile.WriteLine("*  Version                         : V1.0.0      ");
                outputFile.WriteLine("*  Micros supported                : Micro Agnostic (Independant)     ");
                outputFile.WriteLine("*  Compilers supported             : XXXX                                                                           ");
                outputFile.WriteLine("*  Platforms supported             : XXXX                                                                            ");
                outputFile.WriteLine("*  Description            		 : This file contains functions definitions of CanMgr                                                                          ");
                outputFile.WriteLine("*");
                outputFile.WriteLine("*");
                outputFile.WriteLine("*");
                outputFile.WriteLine("* @bug");
                outputFile.WriteLine("  *---------------------------------------------------------------------------------------------------------------------*/");
                outputFile.WriteLine("/**********************************************************************************************************************/");
                outputFile.WriteLine("/* ====================================================================================================================");
                outputFile.WriteLine("*                          I N C L U D E   F I L E S");
                outputFile.WriteLine("* ===================================================================================================================*/");
                outputFile.WriteLine("/**********************************************************************************************************************/");
                outputFile.WriteLine("");
                outputFile.WriteLine("#include \"CanMgr_cfg.h\"");
                outputFile.WriteLine("#include \"CanMgr.h\"");
                outputFile.WriteLine("");
                outputFile.WriteLine("");
                outputFile.WriteLine("/***********************************************************************************************************************");
                outputFile.WriteLine(" *                          M A C R O D E F I N I T I O N S");
                outputFile.WriteLine("***********************************************************************************************************************/");
                outputFile.WriteLine("");

                outputFile.WriteLine("");
                outputFile.WriteLine("#define EINVAL 22");
                outputFile.WriteLine("");
                outputFile.WriteLine("");
                outputFile.WriteLine("/***********************************************************************************************************************");
                outputFile.WriteLine(" *                          V A R I A B L E S D E F I N I  T I O N S");
                outputFile.WriteLine("***********************************************************************************************************************/");
                outputFile.WriteLine("");
                List<String> rxMsg = null;
                int rxMsgCount = 0;
                Dictionary<string, Int16> msgClcTimeRx = new Dictionary<string, Int16>();
                Dictionary<string, Int16> msgClcTimeTx = new Dictionary<string, Int16>();
                if (rxMessage.ContainsKey(selectedNode))
                {
                    rxMsg = rxMessage[selectedNode];
                }

                if (rxMsg != null && rxMsg.Count > 0)
                {
                    for (int ind = 0; ind < rxMsg.Count; ind++)
                    {
                        string clt = messagesRxCycleTime.ContainsKey(rxMsg[ind]) ? messagesRxCycleTime[rxMsg[ind]] : "0";
                        msgClcTimeRx.Add(rxMsg[ind], Int16.Parse(clt));


                    }
                    foreach (String msg in rxMsg)
                    {
                        rxMsgCount++;
                        outputFile.WriteLine("/**");
                        outputFile.WriteLine("* Signals in message " + msg + ".");
                        outputFile.WriteLine("*");
                        outputFile.WriteLine("* All signal values are as on the CAN bus.");
                        outputFile.WriteLine("*/");
                        outputFile.WriteLine("");
                        outputFile.WriteLine("");

                        outputFile.WriteLine("typedef struct {");
                        if (messagesRxSignal.ContainsKey(msg))
                        {

                            List<String> signalsRx = messagesRxSignal[msg];
                            List<string> lens = messagesLength.ContainsKey(msg) ? messagesLength[msg] : null;
                            if (signalsRx != null && signalsRx.Count > 0)
                            {

                                foreach (string sig in signalsRx)
                                {
                                    string dlc = (lens != null && lens.Contains(sig)) ? lens[lens.IndexOf(sig) + 1] : " 0";
                                    string cmethod = "uint64";
                                    if (sig.Equals("Batt48VCell11Volt"))
                                    {
                                        string l = dlc;
                                    }
                                    int sdlc = 0;
                                    try
                                    {
                                        sdlc = Int32.Parse(dlc);
                                    }
                                    catch (Exception e)
                                    {
                                        Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                                    }

                                    if (sdlc <= 8)
                                    {
                                        cmethod = "uint8_t";
                                    }
                                    else if (sdlc <= 16)
                                    {
                                        cmethod = "uint16_t";
                                    }
                                    else if (sdlc <= 32)
                                    {
                                        cmethod = "uint32_t";
                                    }

                                    outputFile.WriteLine(cmethod + " " + SplitCamelCase(sig) + ";");
                                }
                            }
                        }
                        outputFile.WriteLine("}" + fname + "_" + SplitCamelCase(msg) + "_t" + ";");
                        outputFile.WriteLine("");

                        outputFile.WriteLine("static " + fname + "_" + SplitCamelCase(msg) + "_t   " + SplitCamelCase(msg) + ";");
                        outputFile.WriteLine("");
                    }
                }

                List<String> txMsg = null;
                if (txMessage.ContainsKey(selectedNode))
                {
                    txMsg = txMessage[selectedNode];
                }
                int txMsgCount = 0;
                if (txMsg != null && txMsg.Count > 0)
                {
                    for (int ind = 0; ind < txMsg.Count; ind++)
                    {
                        string clt = messagesTxCycleTime.ContainsKey(txMsg[ind]) ? messagesTxCycleTime[txMsg[ind]] : "0";
                        msgClcTimeTx.Add(txMsg[ind], Int16.Parse(clt));
                    }
                    foreach (String msg in txMsg)
                    {
                        txMsgCount++;

                        outputFile.WriteLine("/**");
                        outputFile.WriteLine("* Signals in message " + msg + ".");
                        outputFile.WriteLine("*");
                        outputFile.WriteLine("* All signal values are as on the CAN bus.");
                        outputFile.WriteLine("*/");
                        outputFile.WriteLine("");
                        outputFile.WriteLine("");
                        outputFile.WriteLine("typedef struct {");
                        if (messagesTxSignal.ContainsKey(msg))
                        {
                            List<String> signalsTx = messagesTxSignal[msg];
                            List<string> lens = messagesLength.ContainsKey(msg) ? messagesLength[msg] : null;
                            if (signalsTx != null && signalsTx.Count > 0)
                            {
                                foreach (string sig in signalsTx)
                                {
                                    string dlc = (lens != null && lens.Contains(sig)) ? lens[lens.IndexOf(sig) + 1] : " 0";
                                    string cmethod = "uint64";
                                    if (sig.Equals("Batt48VCell11Volt"))
                                    {
                                        string l = dlc;
                                    }
                                    int sdlc = 0;
                                    try
                                    {
                                        sdlc = Int32.Parse(dlc);
                                    }
                                    catch (Exception e)
                                    {
                                        Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                                    }

                                    if (sdlc <= 8)
                                    {
                                        cmethod = "uint8_t";
                                    }
                                    else if (sdlc <= 16)
                                    {
                                        cmethod = "uint16_t";
                                    }
                                    else if (sdlc <= 32)
                                    {
                                        cmethod = "uint32_t";
                                    }
                                    outputFile.WriteLine(cmethod + " " + SplitCamelCase(sig) + ";");
                                }
                            }
                        }
                        outputFile.WriteLine("}" + fname + "_" + SplitCamelCase(msg) + "_t" + ";");
                        outputFile.WriteLine("");

                        outputFile.WriteLine("static " + fname + "_" + SplitCamelCase(msg) + "_t   " + SplitCamelCase(msg) + ";");
                        outputFile.WriteLine("");

                    }

                    outputFile.WriteLine();
                    // outputFile.WriteLine("uint8_t Init_data_value[CANMGR_MAX_NO_OF_TX_MSGS][8];");
                    outputFile.WriteLine();
                    outputFile.WriteLine();
                    outputFile.WriteLine();
                    outputFile.WriteLine("");
                    outputFile.WriteLine("");
                    foreach (String msg in txMsg)
                    {
                        if (messagesIntitials.ContainsKey(msg) && messagesTxSignal.ContainsKey(msg))
                        {
                            List<String> lsIntitials = messagesIntitials[msg];
                            List<String> lsIntitialsFact = messagesIntitialsFact[msg];
                            List<String> lsIntitialsOffset = messagesIntitialsOffset[msg];
                            string inti = "{";
                            if (lsIntitials != null && lsIntitials.Count > 1)
                            {
                                if (messagesTxInitialsConfig.ContainsKey(lsIntitials[0]))
                                {
                                    inti += messagesTxInitialsConfig[lsIntitials[0]];
                                }
                                else
                                {
                                    double initial = 0;
                                    double intii = 0;
                                    double intiFact = 0;
                                    double intiOffset = 0;
                                    try
                                    {
                                        intii = Double.Parse(lsIntitials[1]);
                                    }
                                    catch (Exception e)
                                    {
                                        Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                                    }
                                    try
                                    {
                                        intiFact = Double.Parse(lsIntitialsFact[1]);
                                    }
                                    catch (Exception e)
                                    {
                                        Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                                    }
                                    try
                                    {
                                        intiOffset = Double.Parse(lsIntitialsOffset[1]);
                                    }
                                    catch (Exception e)
                                    {
                                        Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                                    }
                                    initial = Math.Round((intii * intiFact + intiOffset), 0, MidpointRounding.AwayFromZero);

                                    inti += "" + Convert.ToInt32(initial);
                                }

                                for (int index = 3; index < lsIntitials.Count; index += 2)
                                {
                                    if (messagesTxInitialsConfig.ContainsKey(lsIntitials[index - 1]))
                                    {
                                        inti += "," + messagesTxInitialsConfig[lsIntitials[index - 1]];
                                    }
                                    else
                                    {
                                        double initial = 0;
                                        double intii = 0;
                                        double intiFact = 0;
                                        double intiOffset = 0;
                                        try
                                        {
                                            intii = Double.Parse(lsIntitials[index]);
                                        }
                                        catch (Exception e)
                                        {
                                            Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                                        }
                                        try
                                        {
                                            intiFact = Double.Parse(lsIntitialsFact[index]);
                                        }
                                        catch (Exception e)
                                        {
                                            Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                                        }
                                        try
                                        {
                                            intiOffset = Double.Parse(lsIntitialsOffset[index]);
                                        }
                                        catch (Exception e)
                                        {
                                            Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                                        }
                                        initial = Math.Round((intii * intiFact + intiOffset), 0, MidpointRounding.AwayFromZero);

                                        inti += "," + Convert.ToInt32(initial);
                                    }

                                }
                            }
                            inti += "};";
                            outputFile.WriteLine("static const " + fname + "_" + SplitCamelCase(msg) + "_t default_" + SplitCamelCase(msg) + " =" + inti);
                        }

                    }

                    outputFile.WriteLine("");
                    outputFile.WriteLine("");
                    outputFile.WriteLine("uint8_t Init_data_value[CANMGR_MAX_NO_OF_TX_MSGS][8];");
                    outputFile.WriteLine("");

                    outputFile.WriteLine("");
                }
                outputFile.WriteLine("Rx_Dispatcher_t Rx_Dispatcher[MAX_RX_SIGNALS] = {");


                rxsigCount = 0;
                if (rxMessage.ContainsKey(selectedNode))
                {
                    rxMsg = rxMessage[selectedNode];

                    if (rxMsg != null && rxMsg.Count > 0)
                    {

                        int msgIndex = 0;
                        int msgIndex2 = 0;

                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeRx.OrderBy(key => key.Value))
                        {
                            string msg = clcL.Key;
                            if (messagesRxSignal.ContainsKey(msg))
                            {
                                List<String> rxSignal = messagesRxSignal[msg];
                                foreach (String rs in rxSignal)
                                {
                                    rxsigCount++;
                                    if (msgIndex2 == 0)
                                    {
                                        outputFile.Write("       {" + msgIndex + ",&CanMgr_Read_" + SplitCamelCase(rs) + "}");
                                    }
                                    else
                                    {
                                        outputFile.Write(",");
                                        outputFile.WriteLine();
                                        outputFile.Write("       {" + msgIndex + ",&CanMgr_Read_" + SplitCamelCase(rs) + "}");
                                    }
                                    msgIndex2++;
                                }
                                msgIndex++;
                            }
                        }
                    }
                }
                outputFile.WriteLine();
                outputFile.WriteLine("};");
                outputFile.WriteLine("");
                outputFile.WriteLine("");
                outputFile.WriteLine("");
                outputFile.WriteLine("Rx_SignalIndication_t RxCbk_SignalIndication_Table[MAX_RX_SIGNALS] ={");


                if (rxMessage.ContainsKey(selectedNode))
                {
                    rxMsg = rxMessage[selectedNode];

                    if (rxMsg != null && rxMsg.Count > 0)
                    {

                        int msgIndex = 0;

                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeRx.OrderBy(key => key.Value))
                        {
                            string msg = clcL.Key;
                            if (messagesRxSignal.ContainsKey(msg))
                            {
                                List<String> rxSignal = messagesRxSignal[msg];
                                foreach (String rs in rxSignal)
                                {
                                    if (msgIndex == 0)
                                    {
                                        outputFile.Write("       { CANMGR_" + SplitCamelCase(rs).ToUpper() + "_RXCBK }");
                                    }
                                    else
                                    {
                                        outputFile.Write(",");
                                        outputFile.WriteLine();
                                        outputFile.Write("       { CANMGR_" + SplitCamelCase(rs).ToUpper() + "_RXCBK }");
                                    }
                                    msgIndex++;
                                }

                            }
                        }
                    }
                }
                outputFile.WriteLine();
                outputFile.WriteLine("};");
                outputFile.WriteLine();
                outputFile.WriteLine();

                outputFile.WriteLine("ReceptionTimeout_t Rx_ReceptionTimeoutCbk_Table[MAX_RX_SIGNALS]={");
                if (rxMessage.ContainsKey(selectedNode))
                {
                    rxMsg = rxMessage[selectedNode];

                    if (rxMsg != null && rxMsg.Count > 0)
                    {

                        int msgIndex = 0;
                        int msgIndex2 = 0;

                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeRx.OrderBy(key => key.Value))
                        {
                            string msg = clcL.Key;
                            if (messagesRxSignal.ContainsKey(msg))
                            {
                                List<String> rxSignal = messagesRxSignal[msg];
                                foreach (String rs in rxSignal)
                                {
                                    if (msgIndex2 == 0)
                                    {
                                        outputFile.Write("       {" + msgIndex + ",CANMGR_" + SplitCamelCase(rs).ToUpper() + "_TIMEOUT_CBK}");
                                    }
                                    else
                                    {
                                        outputFile.Write(",");
                                        outputFile.WriteLine();
                                        outputFile.Write("       {" + msgIndex + ",CANMGR_" + SplitCamelCase(rs).ToUpper() + "_TIMEOUT_CBK}");
                                    }
                                    msgIndex2++;
                                }
                                msgIndex++;
                            }
                        }
                    }
                }
                outputFile.WriteLine();
                outputFile.WriteLine("};");
                outputFile.WriteLine();
                outputFile.WriteLine();
                outputFile.WriteLine();
                outputFile.WriteLine("CanMgr_TxInfoTable_t CanMgr_TxInfoTable[CANMGR_MAX_NO_OF_TX_MSGS] = {");

                int indi = 0;
                foreach (KeyValuePair<string, Int16> clcL in msgClcTimeTx.OrderBy(key => key.Value))
                {
                    if (indi == 0)
                    {
                        outputFile.WriteLine("      {");
                        outputFile.WriteLine("          " + SplitCamelCase(clcL.Key).ToUpper() + "_TX_METHOD , ");
                        outputFile.WriteLine("          " + SplitCamelCase(clcL.Key).ToUpper() + "_CLC_TIME,");
                        outputFile.WriteLine("          " + SplitCamelCase(clcL.Key).ToUpper() + "_LENGTH,");
                        outputFile.WriteLine("          " + "0");
                        outputFile.WriteLine("      " + "}");
                    }
                    else
                    {
                        outputFile.WriteLine("      ,");
                        outputFile.WriteLine("      {");
                        outputFile.WriteLine("          " + SplitCamelCase(clcL.Key).ToUpper() + "_TX_METHOD , ");
                        outputFile.WriteLine("          " + SplitCamelCase(clcL.Key).ToUpper() + "_CLC_TIME,");
                        outputFile.WriteLine("          " + SplitCamelCase(clcL.Key).ToUpper() + "_LENGTH,");
                        outputFile.WriteLine("          0");
                        outputFile.WriteLine("          }");
                    }
                    indi++;
                }

                outputFile.WriteLine("};");
                outputFile.WriteLine("");

                if (rxMessage.ContainsKey(selectedNode))
                {
                    rxMsg = rxMessage[selectedNode];


                    if (rxMsg != null && rxMsg.Count > 0)
                    {
                        outputFile.WriteLine("CanMgr_RxInfoTable_t CanMgr_RxInfoTable[CANMGR_MAX_NO_OF_RX_MSGS] = {");
                        outputFile.WriteLine("      {");
                        int index = 0;
                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeRx.OrderBy(key => key.Value))
                        {
                            if (index == 0)
                            {
                                outputFile.WriteLine("          " + SplitCamelCase(clcL.Key).ToUpper() + "_RX_METHOD , ");
                                outputFile.WriteLine("          " + SplitCamelCase(clcL.Key).ToUpper() + "_LENGTH,");
                                outputFile.WriteLine("          " + (rxReceptionTimeout.ContainsKey(clcL.Key) ? rxReceptionTimeout[clcL.Key] : "0") + ",");
                                outputFile.WriteLine("          0");
                                outputFile.WriteLine("          }");
                            }
                            else
                            {
                                outputFile.WriteLine("      ,");
                                outputFile.WriteLine("      {");
                                outputFile.WriteLine("          " + SplitCamelCase(clcL.Key).ToUpper() + "_RX_METHOD , ");
                                outputFile.WriteLine("          " + SplitCamelCase(clcL.Key).ToUpper() + "_LENGTH,");
                                outputFile.WriteLine("          " + (rxReceptionTimeout.ContainsKey(clcL.Key) ? rxReceptionTimeout[clcL.Key].ToString().Equals("") ? "0" : rxReceptionTimeout[clcL.Key] : "0") + ",");
                                outputFile.WriteLine("          0");
                                outputFile.WriteLine("          }");
                            }
                            index++;
                        }
                        outputFile.WriteLine("};");

                    }
                }
                outputFile.WriteLine("");
                outputFile.WriteLine("");

                outputFile.WriteLine("");
                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");

                outputFile.WriteLine("                                  F U N C T I O N S    D E C L A R A T I O N                        ");
                outputFile.WriteLine("* *********************************************************************************************************************/");



                outputFile.WriteLine("");

                if (txMsg != null && txMsg.Count > 0)
                {

                    foreach (String msg in txMsg)
                    {
                        outputFile.WriteLine("/**");
                        outputFile.WriteLine("* Pack message " + msg + ".");
                        outputFile.WriteLine("*");
                        outputFile.WriteLine("* @param[out] dst_p Buffer to pack the message into.");
                        outputFile.WriteLine("* @param[in] src_p Data to pack.");
                        outputFile.WriteLine("* @param[in] size Size of dst_p.");
                        outputFile.WriteLine("*");
                        outputFile.WriteLine("* @return Size of packed data, or negative error code.");
                        outputFile.WriteLine("*/");
                        outputFile.WriteLine("static sint32 " + fname + "_" + SplitCamelCase(msg) + "_pack(");
                        outputFile.WriteLine("      uint8_t *dst_p,");
                        outputFile.WriteLine("      const  " + fname + "_" + SplitCamelCase(msg) + "_t *src_p,");
                        outputFile.WriteLine("      size_t size);");
                        outputFile.WriteLine("");
                        outputFile.WriteLine("");
                        outputFile.WriteLine("");
                    }
                }
                if (rxMsg != null && rxMsg.Count > 0)
                {
                    foreach (KeyValuePair<string, Int16> clcL in msgClcTimeRx.OrderBy(key => key.Value))
                    {
                        string msg = clcL.Key;
                        outputFile.WriteLine("/**");
                        outputFile.WriteLine("* Unpack message " + msg + ".");
                        outputFile.WriteLine("*");
                        outputFile.WriteLine("* @param[out] dst_p Object to unpack the message into.");
                        outputFile.WriteLine("* @param[in] src_p Message to unpack.");
                        outputFile.WriteLine("* @param[in] size Size of src_p.");
                        outputFile.WriteLine("*");
                        outputFile.WriteLine("* @return zero(0) or negative error code.");
                        outputFile.WriteLine("*/");
                        outputFile.WriteLine("static sint32 " + fname + "_" + SplitCamelCase(msg) + "_unpack(");
                        outputFile.WriteLine("      " + fname + "_" + SplitCamelCase(msg) + "_t *dst_p,");
                        outputFile.WriteLine("      const uint8_t *src_p,");
                        outputFile.WriteLine("      size_t size);");
                        outputFile.WriteLine("");
                        outputFile.WriteLine("");
                        outputFile.WriteLine("");
                    }


                    outputFile.WriteLine("/**");
                    outputFile.WriteLine("  * Encode given signal by applying scaling and offset");
                    outputFile.WriteLine("  * @param[in] value Signal to encode.");
                    outputFile.WriteLine("  * @return Encoded signal.");
                    outputFile.WriteLine("*/ ");
                }
                if (txMsg != null && txMsg.Count > 0)
                {

                    foreach (KeyValuePair<string, Int16> clcL in msgClcTimeTx.OrderBy(key => key.Value))
                    {
                        string msg = clcL.Key;
                        if (messagesTxSignal.ContainsKey(msg))
                        {
                            List<String> msgSignals = messagesTxSignal[msg];
                            if (msgSignals != null && msgSignals.Count > 0)
                            {
                                foreach (String sig in msgSignals)
                                {

                                    for (int lineIndex = 0; lineIndex < alllines_encode.Length; lineIndex++)
                                    {
                                        string lineMsg = alllines_encode[lineIndex];
                                        string lineMsgTemp = lineMsg.Replace("_", "").ToLower();
                                        string testMsg = msg.ToLower() + sig.ToLower() + "encode";
                                        if (lineMsgTemp.IndexOf(testMsg.Replace("_", "")) > 0)
                                        {
                                            outputFile.WriteLine("static " + lineMsg.Replace("double value", "float64 value") + "; ");
                                        }
                                    }
                                }
                            }
                        }
                    }


                    outputFile.WriteLine("");
                    outputFile.WriteLine("");
                    if (rxMsg != null && rxMsg.Count > 0)
                    {
                        outputFile.WriteLine("");

                        outputFile.WriteLine("/**");
                        outputFile.WriteLine("  * Decode given signal by applying scaling and offset");
                        outputFile.WriteLine("  * @param[in] value Signal to decode.");
                        outputFile.WriteLine("  * @return Decoded signal.");
                        outputFile.WriteLine("*/ ");
                        foreach (String msg in rxMsg)
                        {
                            if (messagesRxSignal.ContainsKey(msg))
                            {
                                List<String> msgSignals = messagesRxSignal[msg];
                                if (msgSignals != null && msgSignals.Count > 0)
                                {
                                    foreach (String sig in msgSignals)
                                    {
                                        //List<String> msgSignals = messagesTxSignal[msg];
                                        List<string> lens = messagesLength.ContainsKey(msg) ? messagesLength[msg] : null;
                                        string cmethod = "uint64";
                                        if (msgSignals != null && msgSignals.Count > 0)
                                        {
                                            string dlc = (lens != null && lens.Contains(sig)) ? lens[lens.IndexOf(sig) + 1] : " 0";
                                            int sdlc = 0;
                                            try
                                            {
                                                sdlc = Int32.Parse(dlc);
                                            }
                                            catch (Exception e)
                                            {
                                                Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                                            }

                                            if (sdlc <= 8)
                                            {
                                                cmethod = "uint8_t";
                                            }
                                            else if (sdlc <= 16)
                                            {
                                                cmethod = "uint16_t";
                                            }
                                            else if (sdlc <= 32)
                                            {
                                                cmethod = "uint32_t";
                                            }
                                        }
                                        outputFile.WriteLine("static float64 " + fname.Trim() + "_" + SplitCamelCase(msg) + "_" + SplitCamelCase(sig) + "_decode(" + cmethod + " value);");
                                    }
                                }
                            }
                        }

                        outputFile.WriteLine("");
                    }
                    outputFile.WriteLine("");
                    outputFile.WriteLine("");
                    outputFile.WriteLine("/**");
                    outputFile.WriteLine("* Check that given signal is in allowed range.");
                    outputFile.WriteLine("*");
                    outputFile.WriteLine("* @param[in] value Signal to check.");
                    outputFile.WriteLine("*");
                    outputFile.WriteLine("@return true if in range, false otherwise.");
                    outputFile.WriteLine("*/");
                    foreach (String msg in txMsg)
                    {
                        if (messagesTxSignal.ContainsKey(msg))
                        {
                            List<String> msgSignals = messagesTxSignal[msg];
                            if (msgSignals != null && msgSignals.Count > 0)
                            {
                                foreach (String sig in msgSignals)
                                {
                                    List<string> lens = messagesLength.ContainsKey(msg) ? messagesLength[msg] : null;
                                    string cmethod = "uint64";
                                    if (msgSignals != null && msgSignals.Count > 0)
                                    {
                                        string dlc = (lens != null && lens.Contains(sig)) ? lens[lens.IndexOf(sig) + 1] : " 0";
                                        int sdlc = 0;
                                        try
                                        {
                                            sdlc = Int32.Parse(dlc);
                                        }
                                        catch (Exception e)
                                        {
                                            Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                                        }

                                        if (sdlc <= 8)
                                        {
                                            cmethod = "uint8_t";
                                        }
                                        else if (sdlc <= 16)
                                        {
                                            cmethod = "uint16_t";
                                        }
                                        else if (sdlc <= 32)
                                        {
                                            cmethod = "uint32_t";
                                        }
                                    }
                                    outputFile.WriteLine("static boolean " + fname + "_" + SplitCamelCase(msg) + "_" + SplitCamelCase(sig) + "_is_in_range(" + cmethod + " value);");
                                }
                            }
                        }

                    }

                    outputFile.WriteLine("");
                    for (int lineIndex = 0; lineIndex < alllines_static.Length - 1; lineIndex++)
                    {
                        string lineMsg = alllines_static[lineIndex];
                        outputFile.WriteLine(lineMsg);
                    }
                    outputFile.WriteLine("");
                    outputFile.WriteLine("");
                    outputFile.WriteLine("/**********************************************************************************************************************");
                    outputFile.WriteLine("                                    F U N C T I O N S    D E F  I N A T I O N S                        ");
                    outputFile.WriteLine("**********************************************************************************************************************/");
                    outputFile.WriteLine("");
                    foreach (String msg in txMsg)
                    {
                        for (int lineIndex = 0; lineIndex < alllines_pack.Length; lineIndex++)
                        {
                            string lineMsg = alllines_pack[lineIndex].Replace("struct", "");
                            if (lineMsg.Replace("_", "").ToLower().IndexOf(msg.ToLower().Replace("_", "") + "pack") > 0)
                            {
                                outputFile.WriteLine("/**");
                                outputFile.WriteLine("* Pack message " + msg + ".");
                                outputFile.WriteLine("*");
                                outputFile.WriteLine("* @param[out] dst_p Buffer to pack the message into.");
                                outputFile.WriteLine("* @param[in] src_p Data to pack.");
                                outputFile.WriteLine("* @param[in] size Size of dst_p.");
                                outputFile.WriteLine("*");
                                outputFile.WriteLine("* @return Size of packed data, or negative error code.");
                                outputFile.WriteLine("*/");
                                Stack myStack = new Stack();
                                outputFile.WriteLine("static sint32 " + lineMsg.Substring(3));
                                if (lineMsg.IndexOf("{") > -1)
                                {
                                    myStack.Push("{");
                                }
                                lineIndex++;
                                while (lineIndex < alllines_pack.Length)
                                {
                                    lineMsg = alllines_pack[lineIndex].Replace("struct", "");
                                    if (lineMsg.IndexOf("{") > -1)
                                    {
                                        myStack.Push("{");
                                    }
                                    if (lineMsg.IndexOf("}") > -1)
                                    {
                                        myStack.Pop();
                                    }
                                    if (lineMsg.IndexOf("}") > -1 && myStack.Count == 0)
                                    {
                                        outputFile.WriteLine(lineMsg);
                                        break;
                                    }
                                    if (lineMsg.IndexOf("memset(&dst_p") > -1)
                                    {
                                        lineMsg = lineMsg.Replace(");", "u);");
                                    }
                                    outputFile.WriteLine(lineMsg);
                                    lineIndex++;
                                }
                            }
                        }
                    }
                }
                if (rxMsg != null && rxMsg.Count > 0)
                {


                    foreach (String msg in rxMsg)
                    {
                        for (int lineIndex = 0; lineIndex < alllines_unpack.Length; lineIndex++)
                        {

                            string lineMsg = alllines_unpack[lineIndex].Replace("struct", "");
                            if (lineMsg.Replace("_", "").ToLower().IndexOf(msg.ToLower().Replace("_", "") + "unpack") > 0)
                            {
                                outputFile.WriteLine("/**");
                                outputFile.WriteLine("* Unpack message " + msg + ".");
                                outputFile.WriteLine("*");
                                outputFile.WriteLine("*@param[out] dst_p Object to unpack the message into.");
                                outputFile.WriteLine("* @param[in] src_p Message to unpack.");
                                outputFile.WriteLine("* @param[in] size Size of src_p.");
                                outputFile.WriteLine("*");
                                outputFile.WriteLine("* @return zero(0) or negative error code.");
                                outputFile.WriteLine("*/ ");
                                Stack myStack = new Stack();
                                outputFile.WriteLine("static sint32 " + lineMsg.Substring(4));
                                if (lineMsg.IndexOf("{") > -1)
                                {
                                    myStack.Push("{");
                                }
                                lineIndex++;
                                while (lineIndex < alllines_unpack.Length)
                                {
                                    lineMsg = alllines_unpack[lineIndex].Replace("struct", "");
                                    if (lineMsg.IndexOf("{") > -1)
                                    {
                                        myStack.Push("{");
                                    }
                                    if (lineMsg.IndexOf("}") > -1)
                                    {
                                        myStack.Pop();
                                    }
                                    if (lineMsg.IndexOf("}") > -1 && myStack.Count == 0)
                                    {
                                        outputFile.WriteLine(lineMsg);
                                        break;
                                    }
                                    outputFile.WriteLine(lineMsg);
                                    lineIndex++;
                                }
                            }
                        }
                    }
                }
                outputFile.WriteLine("");
                if (txMsg != null && txMsg.Count > 0)
                {
                    foreach (String msg in txMsg)
                    {
                        outputFile.WriteLine("");
                        if (messagesTxSignal.ContainsKey(msg))
                        {
                            List<String> msgSignals = messagesTxSignal[msg];
                            if (msgSignals != null && msgSignals.Count > 0)
                            {

                                foreach (String sig in msgSignals)
                                {

                                    for (int lineIndex = 0; lineIndex < alllines_encode.Length; lineIndex++)
                                    {

                                        string lineMsg = alllines_encode[lineIndex];
                                        string lineMsgTemp = lineMsg.Replace("_", "").ToLower();
                                        string testMsg = msg.ToLower() + sig.ToLower() + "encode";
                                        if (lineMsgTemp.IndexOf(testMsg.Replace("_", "")) > 0)
                                        {
                                            outputFile.WriteLine("/**");
                                            outputFile.WriteLine("  * Encode given signal by applying scaling and offset");
                                            outputFile.WriteLine("  * @param[in] value Signal to encode.");
                                            outputFile.WriteLine("  * @return Encoded signal.");
                                            outputFile.WriteLine("*/ ");
                                            Stack myStack = new Stack();
                                            outputFile.WriteLine("static " + lineMsg.Replace("double value", "float64 value"));
                                            if (lineMsg.IndexOf("{") > -1)
                                            {
                                                myStack.Push("{");
                                            }
                                            lineIndex++;
                                            while (lineIndex < alllines_encode.Length)
                                            {
                                                lineMsg = alllines_encode[lineIndex];
                                                if (lineMsg.IndexOf("{") > -1)
                                                {
                                                    myStack.Push("{");
                                                }
                                                if (lineMsg.IndexOf("}") > -1)
                                                {
                                                    myStack.Pop();
                                                }
                                                if (lineMsg.IndexOf("}") > -1 && myStack.Count == 0)
                                                {
                                                    outputFile.WriteLine(lineMsg);
                                                    break;
                                                }
                                                outputFile.WriteLine(lineMsg);
                                                lineIndex++;
                                            }
                                        }
                                    }
                                }


                                foreach (String sig in msgSignals)
                                {
                                    outputFile.WriteLine("");
                                    for (int lineIndex = 0; lineIndex < alllines_range.Length; lineIndex++)
                                    {
                                        string lineMsg = alllines_range[lineIndex];
                                        string lineMsgTemp = lineMsg.Replace("_", "").ToLower();
                                        string testMsg = msg.ToLower() + sig.ToLower() + "isinrange";
                                        if (lineMsgTemp.IndexOf(testMsg.Replace("_", "")) > 0)
                                        {
                                            outputFile.WriteLine("/* ");
                                            outputFile.WriteLine("  * Check that given signal is in allowed range.                                                                          ");
                                            outputFile.WriteLine("  * @param[in] value Signal to check.                                                                            ");
                                            outputFile.WriteLine("  * @return true if in range, false otherwise                                                                          ");
                                            outputFile.WriteLine("*/ ");
                                            Stack myStack = new Stack();
                                            outputFile.WriteLine("static boolean " + lineMsg.Substring(4));
                                            if (lineMsg.IndexOf("{") > -1)
                                            {
                                                myStack.Push("{");
                                            }
                                            lineIndex++;
                                            while (lineIndex < alllines_range.Length)
                                            {
                                                lineMsg = alllines_range[lineIndex];
                                                if (lineMsg.IndexOf("{") > -1)
                                                {
                                                    myStack.Push("{");
                                                }
                                                if (lineMsg.IndexOf("}") > -1)
                                                {
                                                    myStack.Pop();
                                                }
                                                if (lineMsg.IndexOf("}") > -1 && myStack.Count == 0)
                                                {
                                                    outputFile.WriteLine(lineMsg);
                                                    break;
                                                }
                                                outputFile.WriteLine(lineMsg);
                                                lineIndex++;

                                            }

                                        }
                                    }
                                    outputFile.WriteLine("");
                                }
                            }
                        }
                    }
                }

                outputFile.WriteLine("");
                if (rxMsg != null && rxMsg.Count > 0)
                {
                    foreach (String msg in rxMsg)
                    {
                        outputFile.WriteLine("");
                        if (messagesRxSignal.ContainsKey(msg))
                        {
                            List<String> msgSignals = messagesRxSignal[msg];
                            if (msgSignals != null && msgSignals.Count > 0)
                            {

                                foreach (String sig in msgSignals)
                                {

                                    for (int lineIndex = 0; lineIndex < alllines_decode.Length; lineIndex++)
                                    {
                                        string lineMsg = alllines_decode[lineIndex];
                                        if (lineMsg.Replace("_", "").ToLower().IndexOf(msg.ToLower().Replace("_", "") + sig.ToLower().Replace("_", "") + "decode") > 0)
                                        {
                                            outputFile.WriteLine("/**");
                                            outputFile.WriteLine("  * Decode given signal by applying scaling and offset");
                                            outputFile.WriteLine("  * @param[in] value Signal to decode.");
                                            outputFile.WriteLine("  * @return Decoded signal.");
                                            outputFile.WriteLine("*/ ");
                                            Stack myStack = new Stack();
                                            outputFile.WriteLine("static float64 " + lineMsg.Trim().Substring(6));
                                            if (lineMsg.IndexOf("{") > -1)
                                            {
                                                myStack.Push("{");
                                            }
                                            lineIndex++;
                                            while (lineIndex < alllines_decode.Length)
                                            {
                                                lineMsg = alllines_decode[lineIndex];
                                                if (lineMsg.IndexOf("{") > -1)
                                                {
                                                    myStack.Push("{");
                                                }
                                                if (lineMsg.IndexOf("}") > -1)
                                                {
                                                    myStack.Pop();
                                                }
                                                if (lineMsg.IndexOf("return ") > -1)
                                                {
                                                    lineMsg = lineMsg.Replace("(double)value", "(float64)value");
                                                }
                                                if (lineMsg.IndexOf("}") > -1 && myStack.Count == 0)
                                                {
                                                    outputFile.WriteLine(lineMsg);
                                                    break;
                                                }
                                                outputFile.WriteLine(lineMsg);
                                                lineIndex++;

                                            }

                                        }
                                    }

                                }

                            }
                        }
                    }
                }


                outputFile.WriteLine("");
                outputFile.WriteLine("");

                if (txMsg != null && txMsg.Count > 0)
                {
                    foreach (String msg in txMsg)
                    {
                        if (messagesTxSignal.ContainsKey(msg))
                        {
                            List<String> msgSignals = messagesTxSignal[msg];
                            List<string> lens = messagesLength.ContainsKey(msg) ? messagesLength[msg] : null;
                            if (msgSignals != null && msgSignals.Count > 0)
                            {

                                foreach (String sig in msgSignals)
                                {
                                    string dlc = (lens != null && lens.Contains(sig)) ? lens[lens.IndexOf(sig) + 1] : " 0";
                                    string cmethod = "uint64";

                                    int sdlc = 0;
                                    try
                                    {
                                        sdlc = Int32.Parse(dlc);
                                    }
                                    catch (Exception e)
                                    {
                                        Logger.Log.Instance.Error("Exception encountered with message: " + e.Message);
                                    }

                                    if (sdlc <= 8)
                                    {
                                        cmethod = "uint8_t";
                                    }
                                    else if (sdlc <= 16)
                                    {
                                        cmethod = "uint16_t";
                                    }
                                    else if (sdlc <= 32)
                                    {
                                        cmethod = "uint32_t";
                                    }
                                    outputFile.WriteLine("/* ");
                                    outputFile.WriteLine("  * @Brief  : Updates signal " + sig + "                                                                               ");
                                    outputFile.WriteLine("  * @param  : data                                                                               ");
                                    outputFile.WriteLine("  * @return : E_OK/E_NOT_OK                                                                               ");
                                    outputFile.WriteLine("*/ ");
                                    outputFile.WriteLine("uint8_t CanMgr_Write_" + SplitCamelCase(sig) + "(float64 data)");
                                    outputFile.WriteLine("{");
                                    outputFile.WriteLine("\t\t uint8_t" + " ret;");
                                    outputFile.WriteLine("\t\t " + cmethod + " fl_encoded_data;");
                                    outputFile.WriteLine("\t\t static" + " uint8_t fl_data[" + (SplitCamelCase(msg).ToUpper() + "_LENGTH") + "]={0};");
                                    outputFile.WriteLine("\t\t fl_encoded_data" + " = " + fname + "_" + SplitCamelCase(msg) + "_" + SplitCamelCase(sig) + "_encode(data);");
                                    outputFile.WriteLine("\t\t if(" + fname + "_" + SplitCamelCase(msg) + "_" + SplitCamelCase(sig) + "_is_in_range(fl_encoded_data))");
                                    outputFile.WriteLine("\t\t {");
                                    outputFile.WriteLine("\t\t\t\t " + SplitCamelCase(msg).ToLower() + "." + SplitCamelCase(sig) + " = fl_encoded_data;");
                                    outputFile.WriteLine("\t\t\t\t (void)" + fname + "_" + SplitCamelCase(msg) + "_pack(fl_data,&" + SplitCamelCase(msg).ToLower() + "," + "(size_t)" + SplitCamelCase(msg).ToUpper() + "_LENGTH);");
                                    outputFile.WriteLine("\t\t\t\t ret" + " = CanMgr_SendSignal( " + SplitCamelCase(msg).ToUpper() + ",fl_data);");
                                    outputFile.WriteLine("\t\t }");
                                    outputFile.WriteLine("\t\t else");
                                    outputFile.WriteLine("\t\t {");
                                    outputFile.WriteLine("\t\t \t\t ret" + " = E_NOT_OK;");
                                    outputFile.WriteLine("\t\t }");
                                    outputFile.WriteLine("\t\t return" + "  ret;");
                                    outputFile.WriteLine("}");
                                    outputFile.WriteLine("");
                                    outputFile.WriteLine("");
                                }

                                outputFile.WriteLine("");
                                outputFile.WriteLine("");


                                foreach (String sig in msgSignals)
                                {
                                    outputFile.WriteLine("/* ");
                                    outputFile.WriteLine("  * @Brief  : Returns the transmission status of " + sig + "                                                                               ");
                                    outputFile.WriteLine("  * @param  : NONE                                                                               ");
                                    outputFile.WriteLine("  * @return :Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                                ");
                                    outputFile.WriteLine("*/ ");
                                    outputFile.WriteLine("uint8_t CanMgr_" + SplitCamelCase(sig) + "_cbk(void)");
                                    outputFile.WriteLine("{");
                                    outputFile.WriteLine("  return (CanMgr_GetTransmissionStatus(" + SplitCamelCase(msg).ToUpper() + "));");
                                    outputFile.WriteLine("}");
                                    outputFile.WriteLine("");

                                }
                            }
                        }
                    }
                }

                if (rxMsg != null && rxMsg.Count > 0)
                {
                    foreach (String msg in rxMsg)
                    {
                        if (messagesRxSignal.ContainsKey(msg))
                        {
                            List<String> msgSignals = messagesRxSignal[msg];
                            if (msgSignals != null && msgSignals.Count > 0)
                            {
                                outputFile.WriteLine("");
                                outputFile.WriteLine("");

                                foreach (String sig in msgSignals)
                                {
                                    outputFile.WriteLine("/* ");
                                    outputFile.WriteLine("  * @Brief  : Reads signal " + sig + "                                                                               ");
                                    outputFile.WriteLine("  * @param  : pointer to store the data                                                                               ");
                                    outputFile.WriteLine("  * @return : Reception status                                                                               ");
                                    outputFile.WriteLine("*/ ");

                                    outputFile.WriteLine("uint8_t CanMgr_Read_" + SplitCamelCase(sig) + "(float64* data)");
                                    outputFile.WriteLine("{");
                                    outputFile.WriteLine("static".PadLeft(10) + " uint8_t fl_data[" + SplitCamelCase(msg).ToUpper() + "_LENGTH];");
                                    outputFile.WriteLine("uint8_t".PadLeft(11) + " ret;");
                                    outputFile.WriteLine("ret".PadLeft(7) + " = CanMgr_ReceiveSignal(" + SplitCamelCase(msg).ToUpper() + ",fl_data);");
                                    outputFile.WriteLine("(void)".PadLeft(10) + fname + "_" + SplitCamelCase(msg) + "_unpack(&" + SplitCamelCase(msg).ToLower() + ",fl_data,(size_t)" + SplitCamelCase(msg).ToUpper() + "_LENGTH);");
                                    outputFile.WriteLine("*data =".PadLeft(11) + fname + "_" + SplitCamelCase(msg) + "_" + SplitCamelCase(sig) + "_decode(" + SplitCamelCase(msg).ToLower() + "." + SplitCamelCase(sig) + ");");
                                    outputFile.WriteLine("return".PadLeft(10) + " ret;");
                                    outputFile.WriteLine("}");
                                }

                                outputFile.WriteLine("");
                                outputFile.WriteLine("");
                            }
                        }
                    }
                }
                outputFile.WriteLine("/**");
                outputFile.WriteLine("  * @Brief  : Initializes all the TX message with default value  ");
                outputFile.WriteLine("  * @param  : NONE                                                                               ");
                outputFile.WriteLine("  * @return : NONE                                                                               ");
                outputFile.WriteLine("*/ ");
                outputFile.WriteLine("");
                outputFile.WriteLine("void CanMgr_cfgInit(void)");
                outputFile.WriteLine("{");
                int i = 0;
                if (txMsg != null && txMsg.Count > 0)
                {
                    foreach (String msg in txMsg)
                    {

                        outputFile.WriteLine("(void)".PadLeft(10) + fname + "_" + SplitCamelCase(msg) + "_pack(&Init_data_value[" + SplitCamelCase(msg).ToUpper() + "][" + 0 + "], &default_" + SplitCamelCase(msg) + ", (size_t)" + SplitCamelCase(msg).ToUpper() + "_LENGTH);");
                        i++;
                    }
                }

                outputFile.WriteLine("}");
                outputFile.WriteLine();

                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  *                                                R E V I S I O N   H I S T O R Y             ");
                outputFile.WriteLine("* **********************************************************************************************************************/");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("REVISION NUMBER      : V1.0.0                                                                                   ");
                outputFile.WriteLine("REVISION DATE        : 30/01/2020                                                                               ");
                outputFile.WriteLine("CREATED / REVISED BY : Mahendran L (mahendranl@niyatainfotech.com)                                        ");
                outputFile.WriteLine("DESCRIPTION          : Initial Version                                                                       ");
                outputFile.WriteLine("---------------------------------------------------------------------------------------------------------------------");
                outputFile.WriteLine("***********************************************************************************************************************/");



            }
        }
        private string SplitCamelCase(string inputCamelCaseString)
        {


            inputCamelCaseString = System.Text.RegularExpressions.Regex.Replace(inputCamelCaseString, "(.)([A-Z][a-z]+)", "$1_$2",
              System.Text.RegularExpressions.RegexOptions.Compiled);
            inputCamelCaseString = System.Text.RegularExpressions.Regex.Replace(inputCamelCaseString, "(_+)", "_");
            inputCamelCaseString = System.Text.RegularExpressions.Regex.Replace(inputCamelCaseString, "([a-z0-9])([A-Z])", "$1_$2",
            System.Text.RegularExpressions.RegexOptions.Compiled).ToLower();
            inputCamelCaseString = System.Text.RegularExpressions.Regex.Replace(inputCamelCaseString, "[^a-zA-Z0-9]", "_").Replace("__", "_");
            if (inputCamelCaseString.LastIndexOf("_") == inputCamelCaseString.Length - 1)
            {
                inputCamelCaseString = inputCamelCaseString.Substring(0, inputCamelCaseString.LastIndexOf("_"));
            }

            return inputCamelCaseString;

        }
        private void genHeaderFile()
        {
            using (StreamWriter outputFile = new StreamWriter(Path.Combine(DockingManagerModelHelper.TargetOutputFolderPath, "CanMgr_cfg.h")))
            {

                outputFile.WriteLine("/*********************************************************************************************************************** ");
                outputFile.WriteLine("  *    DISCLAIMER                                                                                                        ");
                outputFile.WriteLine("  *    Copyright (C) 2011, 2016 Niyata Infotech Ptv. Ltd. All rights reserved.                                              ");
                outputFile.WriteLine("  ***********************************************************************************************************************/");
                outputFile.WriteLine("");
                outputFile.WriteLine("/***********************************************************************************************************************");
                outputFile.WriteLine("  * @author              Author : Mahendran L (mahendranl@niyatainfotech.com)                                                                         ");
                outputFile.WriteLine("***********************************************************************************************************************/");
                outputFile.WriteLine("/***********************************************************************************************************************");
                outputFile.WriteLine("  *                                                F I L E  D E S C R I P T I O N                                           ");
                outputFile.WriteLine("  *---------------------------------------------------------------------------------------------------------------------");
                outputFile.WriteLine("*  @brief                                                                                                             ");
                outputFile.WriteLine(" * ");
                outputFile.WriteLine("*  File name                       : CanMgr_cfg.c                                                                         ");
                outputFile.WriteLine("*  Version                         : V1.0.0      ");
                outputFile.WriteLine("*  Micros supported                : Micro Agnostic (Independant)     ");
                outputFile.WriteLine("*  Compilers supported             : XXXX                                                                           ");
                outputFile.WriteLine("*  Platforms supported             : XXXX                                                                            ");
                outputFile.WriteLine("*  Description            		 : This file contains functions definitions of CanMgr                                                                          ");
                outputFile.WriteLine("*");
                outputFile.WriteLine("*");
                outputFile.WriteLine("*");
                outputFile.WriteLine("* @bug");
                outputFile.WriteLine("  *---------------------------------------------------------------------------------------------------------------------*/");
                outputFile.WriteLine("/**********************************************************************************************************************/");
                outputFile.WriteLine("/* ====================================================================================================================");
                outputFile.WriteLine("*                          I N C L U D E   F I L E S");
                outputFile.WriteLine("* ===================================================================================================================*/");
                outputFile.WriteLine("/**********************************************************************************************************************/");
                outputFile.WriteLine("");
                outputFile.WriteLine("");
                outputFile.WriteLine("#ifndef CANMGR_CFG_H_");
                outputFile.WriteLine("#define CANMGR_CFG_H_");
                outputFile.WriteLine("");
                outputFile.WriteLine("#include \"..\\src\\CanMgr_Types.h\"");
                outputFile.WriteLine("#include \"hal_stdtypes.h\"");
                outputFile.WriteLine("");
                if (headerFils != null && headerFils.Count > 0)
                {
                    foreach (string hfile in headerFils)
                    {
                        outputFile.WriteLine("#include \"" + hfile + "\"");
                    }
                }

                outputFile.WriteLine("/**Reception data Callback function mapping table*/");
                outputFile.WriteLine("");
                List<String> rxMsg = null;
                Dictionary<string, Int16> msgClcTimeRx = new Dictionary<string, Int16>();

                if (rxMessage.ContainsKey(selectedNode))
                {
                    rxMsg = rxMessage[selectedNode];

                    if (rxMsg != null && rxMsg.Count > 0)
                    {
                        for (int ind = 0; ind < rxMsg.Count; ind++)
                        {
                            string clt = messagesRxCycleTime.ContainsKey(rxMsg[ind]) ? messagesRxCycleTime[rxMsg[ind]] : "0";
                            msgClcTimeRx.Add(rxMsg[ind], Int16.Parse(clt));


                        }


                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeRx.OrderBy(key => key.Value))
                        {
                            if (messagesRxSignal.ContainsKey(clcL.Key))
                            {
                                List<String> rxSignal = messagesRxSignal[clcL.Key];
                                foreach (String rs in rxSignal)
                                {
                                    outputFile.WriteLine("#define CANMGR_" + SplitCamelCase(rs).ToUpper() + "_RXCBK     " + (rxReceptionCallBackFunction.ContainsKey(rs) && !rxReceptionCallBackFunction[rs].Trim().Equals("") ? "&" + rxReceptionCallBackFunction[rs] : "NULL"));
                                }

                            }


                        }


                        outputFile.WriteLine();
                        outputFile.WriteLine();


                        outputFile.WriteLine(/*Callback function mapping table*/);
                        outputFile.WriteLine("/*Reception timeout Callback function mapping table*/");

                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeRx.OrderBy(key => key.Value))
                        {
                            if (messagesRxSignal.ContainsKey(clcL.Key))
                            {
                                List<String> rxSignal = messagesRxSignal[clcL.Key];
                                foreach (String rs in rxSignal)
                                {
                                    outputFile.WriteLine("#define CANMGR_" + SplitCamelCase(rs).ToUpper() + "_TIMEOUT_CBK       " + (rxReceptionTimeoutCallBack.ContainsKey(rs) && !rxReceptionTimeoutCallBack[rs].Trim().Equals("") ? "&" + rxReceptionTimeoutCallBack[rs] : "NULL"));
                                }

                            }


                        }
                    }

                }

                outputFile.WriteLine();
                outputFile.WriteLine();
                outputFile.WriteLine();
                outputFile.WriteLine();
                outputFile.WriteLine();
                outputFile.WriteLine("/*Remote wakeup callback function*/");
                outputFile.WriteLine("#define APPLICATION_WAKEUP_CBK()   " + ((APPLICATION_WAKEUP_CBK != null && !APPLICATION_WAKEUP_CBK.Trim().Equals("")) ? APPLICATION_WAKEUP_CBK.Trim() + "() " : "NULL"));
                outputFile.WriteLine("/*Network request confirmation callback function*/");
                outputFile.WriteLine("#define APPLICATION_NETWORK_REQUEST_CBK_FUNC(NetworkRequest_Result) " + ((APPLICATION_NETWORK_REQUEST_CBK_FUNC != null && !APPLICATION_NETWORK_REQUEST_CBK_FUNC.Trim().Equals("")) ? APPLICATION_NETWORK_REQUEST_CBK_FUNC.Trim() + "(NetworkRequest_Result)" : "NULL"));
                outputFile.WriteLine("/*Bus off indication callback function*/");
                outputFile.WriteLine("#define APPLICATION_BUSOFF_INDICATION() " + ((APPLICATION_BUSOFF_INDICATION != null && !APPLICATION_BUSOFF_INDICATION.Trim().Equals("")) ? APPLICATION_BUSOFF_INDICATION.Trim() + "()" : "NULL"));
                outputFile.WriteLine("#define INIT_DATA_VALUE    &Init_data_value[0][0]");
                outputFile.WriteLine();
                outputFile.WriteLine();
                outputFile.WriteLine("/*CAN Manager mainfuncion periodicity*/");
                outputFile.WriteLine("#define CANMGR_MAINFUNCTION_PERIOD       " + ((MAINFUNCTION_PERIOD != null && !MAINFUNCTION_PERIOD.Trim().Equals("")) ? MAINFUNCTION_PERIOD.Trim() : "0x0Au "));
                outputFile.WriteLine();
                outputFile.WriteLine();
                outputFile.WriteLine("/*Maximum number of RX signals*/");
                outputFile.WriteLine("#define MAX_RX_SIGNALS        " + rxsigCount + "u");
                outputFile.WriteLine();

                outputFile.WriteLine("/*TX messages in the network node*/");
                List<String> txMsg = null;
                outputFile.WriteLine("typedef enum");
                outputFile.WriteLine("{");
                Dictionary<string, Int16> msgClcTimeTx = new Dictionary<string, Int16>();
                if (txMessage.ContainsKey(selectedNode))
                {
                    txMsg = txMessage[selectedNode];

                    if (txMsg != null && txMsg.Count > 0)
                    {
                        for (int indx = 0; indx < txMsg.Count; indx++)
                        {
                            string clt = messagesTxCycleTime.ContainsKey(txMsg[indx]) ? messagesTxCycleTime[txMsg[indx]] : "0";
                            msgClcTimeTx.Add(txMsg[indx], Int16.Parse(clt));
                        }
                        int ind = 0;

                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeTx.OrderBy(key => key.Value))
                        {
                            outputFile.WriteLine("      " + SplitCamelCase(clcL.Key).ToUpper() + "=" + ind + "u,");
                            ind++;
                        }
                    }
                    outputFile.WriteLine("       CANMGR_MAX_NO_OF_TX_MSGS =" + txMsg.Count + "u");
                }
                outputFile.WriteLine("}Tx_Msg_Id;");
                outputFile.WriteLine();


                outputFile.WriteLine("/*RX messages in the network node*/");
                outputFile.WriteLine("typedef enum");
                outputFile.WriteLine("{");

                if (rxMessage.ContainsKey(selectedNode))
                {
                    rxMsg = rxMessage[selectedNode];

                    if (rxMsg != null && rxMsg.Count > 0)
                    {


                        int ind = 0;

                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeRx.OrderBy(key => key.Value))
                        {
                            outputFile.WriteLine("      " + SplitCamelCase(clcL.Key).ToUpper() + "=" + ind + "u,");
                            ind++;
                        }
                    }
                    outputFile.WriteLine("       CANMGR_MAX_NO_OF_RX_MSGS= " + rxMsg.Count + "u");
                }
                outputFile.WriteLine("}Rx_Msg_Id;");
                outputFile.WriteLine();
                outputFile.WriteLine();

                outputFile.WriteLine(/* Tx Frame ids. */);
                outputFile.WriteLine("/*TX messages indentifier*/");
                outputFile.WriteLine("typedef enum");
                outputFile.WriteLine("{");
                if (txMessage.ContainsKey(selectedNode))
                {
                    txMsg = txMessage[selectedNode];

                    if (txMsg != null && txMsg.Count > 0)
                    {
                        int findx = 0;
                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeTx.OrderBy(key => key.Value))
                        {
                            if (findx == 0)
                            {
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_FRAME_ID" + " = " + (messagesTxFrameIds.ContainsKey(clcL.Key) ? "(" + messagesTxFrameIds[txMsg[txMsg.IndexOf(clcL.Key)]] + ")" : "(0x0000)"));
                            }
                            else
                            {
                                outputFile.Write(",");
                                outputFile.WriteLine();
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_FRAME_ID" + " = " + (messagesTxFrameIds.ContainsKey(clcL.Key) ? "(" + messagesTxFrameIds[txMsg[txMsg.IndexOf(clcL.Key)]] + ")" : "(0x0000)"));

                            }
                            findx++;
                        }
                    }
                }
                outputFile.WriteLine();
                outputFile.WriteLine("}Tx_Mxg_Frame_Id;");
                outputFile.WriteLine();



                outputFile.WriteLine(/* Rx Frame ids. */);
                outputFile.WriteLine("/*RX messages indentifier*/");
                outputFile.WriteLine("typedef enum");
                outputFile.WriteLine("{");

                if (rxMessage.ContainsKey(selectedNode))
                {
                    rxMsg = rxMessage[selectedNode];

                    if (rxMsg != null && rxMsg.Count > 0)
                    {
                        int findx = 0;
                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeRx.OrderBy(key => key.Value))
                        {
                            if (findx == 0)
                            {
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_FRAME_ID" + " = " + (messagesRxFrameIds.ContainsKey(clcL.Key) ? "(" + messagesRxFrameIds[rxMsg[rxMsg.IndexOf(clcL.Key)]] + ")" : "(0x0000)"));
                            }
                            else
                            {
                                outputFile.Write(",");
                                outputFile.WriteLine();
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_FRAME_ID" + " = " + (messagesRxFrameIds.ContainsKey(clcL.Key) ? "(" + messagesRxFrameIds[rxMsg[rxMsg.IndexOf(clcL.Key)]] + ")" : "(0x0000)"));
                            }
                            findx++;
                        }
                    }
                }
                outputFile.WriteLine();
                outputFile.WriteLine("}Rx_Mxg_Frame_Id;");
                outputFile.WriteLine();

                outputFile.WriteLine("/* Tx Frame lengths in bytes. */");
                outputFile.WriteLine();
                outputFile.WriteLine();

                outputFile.WriteLine("typedef enum");
                outputFile.WriteLine("{");
                if (txMessage.ContainsKey(selectedNode))
                {
                    txMsg = txMessage[selectedNode];

                    if (txMsg != null && txMsg.Count > 0)
                    {
                        int findx = 0;
                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeTx.OrderBy(key => key.Value))
                        {
                            if (findx == 0)
                            {
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_LENGTH" + " = " + (messagesTxDLC.ContainsKey(clcL.Key) ? "(" + messagesTxDLC[txMsg[txMsg.IndexOf(clcL.Key)]] + "u)" : "(0u)"));
                            }
                            else
                            {
                                outputFile.Write(",");
                                outputFile.WriteLine();
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_LENGTH" + " = " + (messagesTxDLC.ContainsKey(clcL.Key) ? "(" + messagesTxDLC[txMsg[txMsg.IndexOf(clcL.Key)]] + "u)" : "(0u)"));

                            }
                            findx++;
                        }
                    }

                }
                outputFile.WriteLine();
                outputFile.WriteLine("}Tx_Mxg_Length;");
                outputFile.WriteLine();


                outputFile.WriteLine("/* Rx Frame lengths in bytes. */");
                outputFile.WriteLine();
                outputFile.WriteLine();

                outputFile.WriteLine("typedef enum");
                outputFile.WriteLine("{");
                if (rxMessage.ContainsKey(selectedNode))
                {
                    rxMsg = rxMessage[selectedNode];

                    if (rxMsg != null && rxMsg.Count > 0)
                    {
                        int findx = 0;
                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeRx.OrderBy(key => key.Value))
                        {
                            if (findx == 0)
                            {
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_LENGTH" + " = " + (messagesRxDLC.ContainsKey(clcL.Key) ? "(" + messagesRxDLC[rxMsg[rxMsg.IndexOf(clcL.Key)]] + "u)" : "(0u)"));
                            }
                            else
                            {
                                outputFile.Write(",");
                                outputFile.WriteLine();
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_LENGTH" + " = " + (messagesRxDLC.ContainsKey(clcL.Key) ? "(" + messagesRxDLC[rxMsg[rxMsg.IndexOf(clcL.Key)]] + "u)" : "(0u)"));

                            }
                            findx++;
                        }
                    }

                }
                outputFile.WriteLine();
                outputFile.WriteLine("}Rx_Mxg_Length;");
                outputFile.WriteLine();


                outputFile.WriteLine("/* Tx CLC Time. */");
                outputFile.WriteLine();
                outputFile.WriteLine();

                outputFile.WriteLine("typedef enum");
                outputFile.WriteLine("{");
                if (txMessage.ContainsKey(selectedNode))
                {
                    txMsg = txMessage[selectedNode];

                    if (txMsg != null && txMsg.Count > 0)
                    {

                        int indi = 0;
                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeTx.OrderBy(key => key.Value))
                        {
                            if (indi == 0)
                            {
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_CLC_TIME   =(" + clcL.Value + "u)");
                            }
                            else
                            {
                                outputFile.Write(",");
                                outputFile.WriteLine();
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_CLC_TIME = (" + clcL.Value + "u)");

                            }
                            indi++;

                        }



                    }

                }
                outputFile.WriteLine();
                outputFile.WriteLine("}Tx_Message_cycle_time;");
                outputFile.WriteLine();




                outputFile.WriteLine("/* Rx CLC Time. */");
                outputFile.WriteLine();
                outputFile.WriteLine();

                outputFile.WriteLine("typedef enum");
                outputFile.WriteLine("{");
                if (rxMessage.ContainsKey(selectedNode))
                {
                    rxMsg = rxMessage[selectedNode];

                    if (rxMsg != null && rxMsg.Count > 0)
                    {

                        int indi = 0;
                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeRx.OrderBy(key => key.Value))
                        {
                            if (indi == 0)
                            {
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_CLC_TIME   =(" + clcL.Value + "u)");
                            }
                            else
                            {
                                outputFile.Write(",");
                                outputFile.WriteLine();
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_CLC_TIME = (" + clcL.Value + "u)");

                            }
                            indi++;

                        }

                    }

                }
                outputFile.WriteLine();
                outputFile.WriteLine("}Rx_Message_cycle_time;");
                outputFile.WriteLine();



                outputFile.WriteLine("/* Extended or standard frame types.. */");
                outputFile.WriteLine();
                outputFile.WriteLine();

                outputFile.WriteLine("typedef enum");
                outputFile.WriteLine("{");
                if (txMessage.ContainsKey(selectedNode))
                {
                    txMsg = txMessage[selectedNode];

                    if (txMsg != null && txMsg.Count > 0)
                    {
                        int findx = 0;
                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeTx.OrderBy(key => key.Value))
                        {
                            if (findx == 0)
                            {
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_IS_EXTENDED" + " = " + (messagesExtended.ContainsKey(clcL.Key) ? (messagesExtended[txMsg[txMsg.IndexOf(clcL.Key)]].Equals("False") ? "(0)" : "1") : "(0)"));
                            }
                            else
                            {
                                outputFile.Write(",");
                                outputFile.WriteLine();
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_IS_EXTENDED" + " = " + (messagesExtended.ContainsKey(clcL.Key) ? (messagesExtended[txMsg[txMsg.IndexOf(clcL.Key)]].Equals("False") ? "(0)" : "1") : "(0)"));

                            }
                            findx++;
                        }

                    }

                }
                outputFile.WriteLine();
                outputFile.WriteLine("}Tx_Msg_Identifier_Type;");
                outputFile.WriteLine();




                outputFile.WriteLine("typedef enum");
                outputFile.WriteLine("{");
                if (rxMessage.ContainsKey(selectedNode))
                {
                    rxMsg = rxMessage[selectedNode];

                    if (rxMsg != null && rxMsg.Count > 0)
                    {
                        int findx = 0;
                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeRx.OrderBy(key => key.Value))
                        {
                            if (findx == 0)
                            {
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_IS_EXTENDED" + " = " + (messagesExtended.ContainsKey(clcL.Key) ? (messagesExtended[rxMsg[rxMsg.IndexOf(clcL.Key)]].Equals("False") ? "(0)" : "1") : "(0)"));
                            }
                            else
                            {
                                outputFile.Write(",");
                                outputFile.WriteLine();
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_IS_EXTENDED" + " = " + (messagesExtended.ContainsKey(clcL.Key) ? (messagesExtended[rxMsg[rxMsg.IndexOf(clcL.Key)]].Equals("False") ? "(0)" : "1") : "(0)"));

                            }
                            findx++;
                        }
                    }

                }
                outputFile.WriteLine();
                outputFile.WriteLine("}Rx_Msg_Identifier_Type;");
                outputFile.WriteLine();



                outputFile.WriteLine("/* Tx Methods. */");
                outputFile.WriteLine();
                outputFile.WriteLine();

                outputFile.WriteLine("typedef enum");
                outputFile.WriteLine("{");
                if (txMessage.ContainsKey(selectedNode))
                {
                    txMsg = txMessage[selectedNode];

                    if (txMsg != null && txMsg.Count > 0)
                    {
                        int findx = 0;
                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeTx.OrderBy(key => key.Value))
                        {
                            string vl = "(0u)";
                            string ms = txMsg[txMsg.IndexOf(clcL.Key)];
                            if (messagesTxMethod.ContainsKey(ms))
                            {
                                String mt = messagesTxMethod[ms];
                                if (mt.Equals("Event"))
                                {
                                    vl = "2u";
                                }
                                else if (mt.Equals("Cyclic"))
                                {
                                    vl = "0u";
                                }
                                else if (mt.Equals("Combined"))
                                {
                                    vl = "1u";
                                }
                            }
                            if (findx == 0)
                            {
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_TX_METHOD" + " = " + vl);
                            }
                            else
                            {
                                outputFile.Write(",");
                                outputFile.WriteLine();
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_TX_METHOD" + " = " + vl);

                            }
                            findx++;
                        }


                    }

                }
                outputFile.WriteLine();
                outputFile.WriteLine("}Tx_Msg_Method;");
                outputFile.WriteLine();



                outputFile.WriteLine("/* Rx Methods. */");
                outputFile.WriteLine();
                outputFile.WriteLine();

                outputFile.WriteLine("typedef enum");
                outputFile.WriteLine("{");
                if (rxMessage.ContainsKey(selectedNode))
                {
                    rxMsg = rxMessage[selectedNode];

                    if (rxMsg != null && rxMsg.Count > 0)
                    {
                        int findx = 0;
                        foreach (KeyValuePair<string, Int16> clcL in msgClcTimeRx.OrderBy(key => key.Value))
                        {
                            string vl = "(0u)";
                            string ms = rxMsg[rxMsg.IndexOf(clcL.Key)];
                            if (messagesRxMethod.ContainsKey(ms))
                            {
                                String mt = messagesRxMethod[ms];
                                if (mt.Equals("Event"))
                                {
                                    vl = "2u";
                                }
                                else if (mt.Equals("Cyclic"))
                                {
                                    vl = "0u";
                                }
                                else if (mt.Equals("Combined"))
                                {
                                    vl = "1u";
                                }
                            }
                            if (findx == 0)
                            {
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_RX_METHOD" + " = " + vl);
                            }
                            else
                            {
                                outputFile.Write(",");
                                outputFile.WriteLine();
                                outputFile.Write("      " + SplitCamelCase(clcL.Key).ToUpper() + "_RX_METHOD" + " = " + vl);

                            }
                            findx++;
                        }
                    }

                }
                outputFile.WriteLine();
                outputFile.WriteLine("}Rx_Msg_Method;");
                outputFile.WriteLine();
                outputFile.WriteLine();
                outputFile.WriteLine("extern uint8_t Init_data_value[CANMGR_MAX_NO_OF_TX_MSGS][8];");
                outputFile.WriteLine();

                outputFile.WriteLine("");
                outputFile.WriteLine("typedef struct");
                outputFile.WriteLine("{");
                outputFile.WriteLine("   Tx_Msg_Method  frame_type;");
                outputFile.WriteLine("  Tx_Message_cycle_time period;");
                outputFile.WriteLine("  Tx_Mxg_Length  length;");
                outputFile.WriteLine("  uint16_t counter;");
                outputFile.WriteLine("}CanMgr_TxInfoTable_t;");
                outputFile.WriteLine("");

                outputFile.WriteLine("typedef uint8_t(*CanMgr_Read)(float64* data);");
                outputFile.WriteLine("");

                outputFile.WriteLine("");
                outputFile.WriteLine("typedef struct ");
                outputFile.WriteLine("{");
                outputFile.WriteLine("   uint8_t Message_Index;");
                outputFile.WriteLine("  CanMgr_Read Message_funcptr;");
                outputFile.WriteLine("}Rx_Dispatcher_t;");

                outputFile.WriteLine("");
                outputFile.WriteLine("typedef void (*Rx_SignalIndication)(void);");
                outputFile.WriteLine("");
                outputFile.WriteLine("typedef struct");
                outputFile.WriteLine("{");
                outputFile.WriteLine("  Rx_SignalIndication Rx_SignalIndication_cbkFuncPtr; ");
                outputFile.WriteLine("}Rx_SignalIndication_t;");
                outputFile.WriteLine("");
                outputFile.WriteLine("");
                outputFile.WriteLine("typedef struct ");
                outputFile.WriteLine("{");
                outputFile.WriteLine("  uint8_t  Message_Index;");
                outputFile.WriteLine("  Rx_SignalIndication RxSignal_ReceptionTimeout_cbkFuncPtr;");
                outputFile.WriteLine("  }ReceptionTimeout_t;");
                outputFile.WriteLine("");
                outputFile.WriteLine("");
                outputFile.WriteLine("extern ReceptionTimeout_t Rx_ReceptionTimeoutCbk_Table[MAX_RX_SIGNALS];");
                outputFile.WriteLine("extern Rx_SignalIndication_t RxCbk_SignalIndication_Table[MAX_RX_SIGNALS];");
                outputFile.WriteLine("extern Rx_Dispatcher_t Rx_Dispatcher[MAX_RX_SIGNALS];");
                outputFile.WriteLine("");
                outputFile.WriteLine("");
                outputFile.WriteLine("");

                outputFile.WriteLine("typedef struct");
                outputFile.WriteLine("{");
                outputFile.WriteLine("   Rx_Msg_Method frame_type;");
                outputFile.WriteLine("   Rx_Mxg_Length length;");
                outputFile.WriteLine("  uint16_t timeout;");
                outputFile.WriteLine("  uint16_t timeout_counter;");
                outputFile.WriteLine("}CanMgr_RxInfoTable_t;");
                outputFile.WriteLine("");
                outputFile.WriteLine("");
                outputFile.WriteLine("extern CanMgr_TxInfoTable_t CanMgr_TxInfoTable[CANMGR_MAX_NO_OF_TX_MSGS];");
                outputFile.WriteLine("");
                outputFile.WriteLine("");
                outputFile.WriteLine("extern CanMgr_RxInfoTable_t CanMgr_RxInfoTable[CANMGR_MAX_NO_OF_RX_MSGS];");
                outputFile.WriteLine("");
                outputFile.WriteLine("void CanMgr_cfgInit(void);");
                outputFile.WriteLine("");

               
                if (txMsg != null && txMsg.Count > 0)
                {
                    foreach (String msg in txMsg)
                    {
                        if (messagesTxSignal.ContainsKey(msg))
                        {
                            List<String> txSignals = messagesTxSignal[msg];
                            if (txSignals != null && txSignals.Count > 0)
                            {
                                outputFile.WriteLine("");
                                outputFile.WriteLine("/* ");
                                outputFile.WriteLine("  * @Brief  : The following functions shall be used by the application to update signal to be transmitted");
                                outputFile.WriteLine("  * @param  : data                                                                               ");
                                outputFile.WriteLine("  * @return : E_OK/E_NOT_OK                                                                               ");
                                outputFile.WriteLine("*/ ");
                                outputFile.WriteLine("");
                                foreach (String sig in txSignals)
                                {
                                    
                                    outputFile.WriteLine("uint8_t CanMgr_Write_" + SplitCamelCase(sig) + "(float64 data);");
                                }
                                outputFile.WriteLine("");
                                outputFile.WriteLine("/* ");
                                outputFile.WriteLine("  * @Brief  : The following functions shall be used by the application to check transmission status");
                                outputFile.WriteLine("  * @param  : NONE                                                                               ");
                                outputFile.WriteLine("  * @return : Transmission Status (TRANSMISSION_SUCCESS / TRANSMISSION_FAILED)                                                                               ");
                                outputFile.WriteLine("*/ ");
                                outputFile.WriteLine("");
                                foreach (String sig in txSignals)
                                {
                                    outputFile.WriteLine("uint8_t CanMgr_" + SplitCamelCase(sig) + "_cbk(void);");
                                }

                                outputFile.WriteLine("");
                                outputFile.WriteLine("");



                            }
                        }
                    }

                }
                outputFile.WriteLine("");

                outputFile.WriteLine("");
                if (rxMsg != null && rxMsg.Count > 0)
                {
                    foreach (String msg in rxMsg)
                    {
                        if (messagesRxSignal.ContainsKey(msg))
                        {
                            List<String> rxSignals = messagesRxSignal[msg];
                            if (rxSignals != null && rxSignals.Count > 0)
                            {
                                outputFile.WriteLine("");
                                outputFile.WriteLine("/* ");
                                outputFile.WriteLine("* @Brief  : The following functions shall be used by the application to check transmission status");
                                outputFile.WriteLine("  * @param  : pointer to store the data                                                                                ");
                                outputFile.WriteLine("  * @return : Reception status (MSG_RECEIVED / MSG_MISSING /MSG_NEVER_RECEIVED)                                                                               ");
                                outputFile.WriteLine("*/ ");
                                outputFile.WriteLine("");
                                foreach (String sig in rxSignals)
                                {
                                    outputFile.WriteLine("uint8_t CanMgr_Read_" + SplitCamelCase(sig) + "(float64* data);");
                                }



                            }
                        }
                    }

                }
                outputFile.WriteLine("");
                outputFile.WriteLine("   /**********************************************************************************************************************");
                outputFile.WriteLine("  *                                                R E V I S I O N   H I S T O R Y             ");
                outputFile.WriteLine("* **********************************************************************************************************************/");
                outputFile.WriteLine("             /**********************************************************************************************************************");
                outputFile.WriteLine("                 REVISION NUMBER      : V1.0.0                                                                                   ");
                outputFile.WriteLine("               REVISION DATE        : 30/01/2020                                                                               ");
                outputFile.WriteLine("              CREATED / REVISED BY : Mahendran L (mahendranl@niyatainfotech.com)                                        ");
                outputFile.WriteLine("              DESCRIPTION          : Initial Version                                                                       ");
                outputFile.WriteLine("       ---------------------------------------------------------------------------------------------------------------------");
                outputFile.WriteLine("       * **********************************************************************************************************************/");

                outputFile.WriteLine("#endif /* CANMGR_CFG_H_ */");







            }

        }
        private void GenerateBtnCanIf_Click(object sender, RoutedEventArgs e)
        {
            String Message = "Output Files Generated and Saved Successfully at following path : " + DockingManagerModelHelper.TargetOutputFolderPath;
            geneRateCanIfC();
            geneRateCanIfHeader();

            MessageBox.Show(Message);

        }
        private void geneRateCanIfHeader()
        {
            using (StreamWriter outputFile = new StreamWriter(Path.Combine(DockingManagerModelHelper.TargetOutputFolderPath, "CanIF_cfg.h")))
            {

                outputFile.WriteLine("#ifndef CANIF_CFG_H");
                outputFile.WriteLine("#define CANIF_CFG_H");
                outputFile.WriteLine("/*********************************************************************************************************************** ");
                outputFile.WriteLine("  *    DISCLAIMER                                                                                                        ");
                outputFile.WriteLine("  *   Copyright (C) 2011, 2016 Niyata Infotech Ptv. Ltd. All rights reserved.                                              ");
                outputFile.WriteLine("  ***********************************************************************************************************************/");
                outputFile.WriteLine("");
                outputFile.WriteLine("/***********************************************************************************************************************");
                outputFile.WriteLine("  * @author              Author : Akshay Bavalatti (akshayb@niyatainfotech.com)                                                                         ");
                outputFile.WriteLine("***********************************************************************************************************************/");
                outputFile.WriteLine("/***********************************************************************************************************************");
                outputFile.WriteLine("  *                                                F I L E  D E S C R I P T I O N                                           ");
                outputFile.WriteLine("  *---------------------------------------------------------------------------------------------------------------------");
                outputFile.WriteLine("*  @brief                                                                                                             ");
                outputFile.WriteLine(" * ");
                outputFile.WriteLine("*  File name                       : CanIF_cfg.h                                                                         ");
                outputFile.WriteLine("*  Version                         : V1.0.0      ");
                outputFile.WriteLine("*  Micros supported                : Micro Agnostic (Independant)     ");
                outputFile.WriteLine("*  Compilers supported             : XXXX                                                                           ");
                outputFile.WriteLine("*  Platforms supported             : XXXX                                                                            ");
                outputFile.WriteLine("*  Description                     : This file contains precompile configuration settings for CanIF                                ");
                outputFile.WriteLine("*                                                                                                                     ");
                outputFile.WriteLine("*                                                                                                                     ");
                outputFile.WriteLine("*  @bug                                                                                                               ");
                outputFile.WriteLine("*---------------------------------------------------------------------------------------------------------------------*/");
                outputFile.WriteLine("/**********************************************************************************************************************/");
                outputFile.WriteLine("#ifdef __cplusplus");
                outputFile.WriteLine("extern \"C\" {");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("/**********************************************************************************************************************/");
                outputFile.WriteLine("/* ====================================================================================================================");
                outputFile.WriteLine("*                          I N C L U D E   F I L E S");
                outputFile.WriteLine("* ===================================================================================================================*/");
                outputFile.WriteLine("");
                outputFile.WriteLine("#include \"CanIF_Types.h\"");
                outputFile.WriteLine("#include \"CanIF_cbk.h\"");
                if (headerFilsCanIf != null && headerFilsCanIf.Count > 0)
                {
                    foreach (string hfile in headerFilsCanIf)
                    {
                        outputFile.WriteLine("#include \"" + hfile + "\"");
                    }
                }
                outputFile.WriteLine("/* ====================================================================================================================");
                outputFile.WriteLine(" *                          C O N F I G U R A T I O N");
                outputFile.WriteLine("* ===================================================================================================================*/");
                outputFile.WriteLine("");
                //outputFile.WriteLine("#define NOT_AUTOSAR_IMPLEMENTATION");
                outputFile.WriteLine("");
                outputFile.WriteLine("#define NOT_AUTOSAR_IMPLEMENTATION");
                outputFile.WriteLine("");
                int totalTxBasicCanMessage = 0;
                int totalTxBacicCanMailBox = 0;
                int totalTxMessages = 0;
                int totalRxMessages = 0;
                foreach (KeyValuePair<string, string> kvp in mailBoxCanif)
                {
                    if (kvp.Value.Equals("CANIF_TxBasicCANMailbox"))
                    {

                        totalTxBacicCanMailBox++;
                        if (mailBoxMessage.ContainsKey(kvp.Key))
                        {
                            totalTxBasicCanMessage++;
                            totalTxMessages++;
                        }
                        if (mailBoxMessageMore.ContainsKey(kvp.Key))
                        {
                            totalTxBasicCanMessage += mailBoxMessageMore[kvp.Key].Count;
                            totalTxMessages += mailBoxMessageMore[kvp.Key].Count;
                        }

                    }
                    else if (kvp.Value.Equals("CANIF_TxFullCANMailbox"))
                    {
                        totalTxMessages++;
                    }
                    else if (kvp.Value.Equals("CANIF_RxBasicCANMailbox"))
                    {
                        if (mailBoxMessageRx.ContainsKey(kvp.Key))
                        {

                            totalRxMessages++;
                        }
                        if (mailBoxMessageMoreRx.ContainsKey(kvp.Key))
                        {

                            totalRxMessages += mailBoxMessageMoreRx[kvp.Key].Count;
                        }
                    }
                    else if (kvp.Value.Equals("CANIF_RxFullCANMailbox"))
                    {
                        totalRxMessages++;
                    }

                }


                outputFile.WriteLine("#define CANIF_TOTAL_TX_BUFFER_MESSAGE    " + totalTxBasicCanMessage + "U");
                outputFile.WriteLine("");
                outputFile.WriteLine("#define CANIF_TOTAL_NUM_OF_MAILBOX_CONIGURED_TO_STORE_TX_BUFFERS " + totalTxBacicCanMailBox + "U");
                outputFile.WriteLine("");
                outputFile.WriteLine("#define CANIF_TOTAL_RX_PDU                    " + totalRxMessages + "U"); ;
                outputFile.WriteLine("");
                outputFile.WriteLine("#define CANIF_TOTAL_TX_MESSAGES          " + totalTxMessages + "U");
                outputFile.WriteLine("");
                outputFile.WriteLine("#define CANIF_TOTAL_RX_INIDICATION_FUNC   5U");
                outputFile.WriteLine("");
                outputFile.WriteLine("#define CANIF_TOTAL_NUM_OF_MAIL_BOX           " + lstMailConfigParentsMailBox.Count + "U");

                outputFile.WriteLine("");
                outputFile.WriteLine("#define CANIF_CFG_RX_MAXVALIDRXDLC       " + lstMailConfigParentsMailBox.Count + "U");
                outputFile.WriteLine("");
                outputFile.WriteLine("#define CANIF_CFG_MAX_MAILBOXES          " + lstMailConfigParentsMailBox.Count + "U");
                outputFile.WriteLine("");
                outputFile.WriteLine("#define CANIF_CFG_MAX_TXPDUS  CANIF_TOTAL_TX_MESSAGES");
                outputFile.WriteLine("");
                outputFile.WriteLine("#define CANIF_CFG_MAX_RXPDUS            CANIF_TOTAL_RX_PDU");
                outputFile.WriteLine("");
                outputFile.WriteLine("#define CANIF_CFG_MAX_RXINDICATIONS     CANIF_TOTAL_RX_INIDICATION_FUNC");
                outputFile.WriteLine("");
                outputFile.WriteLine("#define CANIF_CFG_MAX_CONTROLLER          1U");
                outputFile.WriteLine("");
                outputFile.WriteLine("#define CANIF_TOTAL_TX_CONFIRMATION_FUNC_LIST 5U");
                outputFile.WriteLine("");
                outputFile.WriteLine("#define CANIF_STATE_MACHINE_ERROR_COUNTER_LIMIT  5U");
                outputFile.WriteLine("");
                outputFile.WriteLine("#define CANIF_STATE_MACHINE_TIMEOUT_LIMIT        " + (StateMachineTimeout != null && !StateMachineTimeout.Trim().Equals("") ? StateMachineTimeout + "U" : "5U"));
                outputFile.WriteLine("");
                outputFile.WriteLine("#define CANIF_WAIT_FOR_SLEEP_TIMEOUT    " + (WaitforSleepTimeout != null && !WaitforSleepTimeout.Trim().Equals("") ? WaitforSleepTimeout + "U" : "10U"));
                outputFile.WriteLine("");
                outputFile.WriteLine("#ifdef CANIF_BASIC_CAN");
                outputFile.WriteLine("typedef union CanIf_TxQueueUTag");
                outputFile.WriteLine("{  /* PRQA S 0750 */  /* MD_CSL_18.4 */");
                outputFile.WriteLine("  CanIf_TxPrioByCanIdByteQueueType raw[CANIF_TOTAL_TX_BUFFER_MESSAGE];");
                outputFile.WriteLine("} CanIf_TxQueueUType;");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("");
                outputFile.WriteLine("typedef union CanIf_CtrlStatesUTag");
                outputFile.WriteLine("{");
                outputFile.WriteLine("  CanIf_CtrlStatesType raw[CANIF_CFG_MAX_CONTROLLER];");
                outputFile.WriteLine("} CanIf_CtrlStatesUType;");
                outputFile.WriteLine("");
                outputFile.WriteLine("#ifdef CANIF_BASIC_CAN");
                outputFile.WriteLine("/**   \\brief  type to access CanIf_TxBufferPrioByCanIdBase in an index and symbol based style. */");
                outputFile.WriteLine("typedef union CanIf_TxBufferPrioByCanIdBaseUTag");
                outputFile.WriteLine("{  /* PRQA S 0750 */  /* MD_CSL_18.4 */");
                outputFile.WriteLine("  CanIf_TxBufferPrioByCanIdBaseType raw[CANIF_TOTAL_NUM_OF_MAILBOX_CONIGURED_TO_STORE_TX_BUFFERS];");
                outputFile.WriteLine("} CanIf_TxBufferPrioByCanIdBaseUType;");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_BusOffNotificationFctPtr");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("");
                outputFile.WriteLine("/**");
                outputFile.WriteLine(" * ");
                outputFile.WriteLine(" */ ");
                outputFile.WriteLine("extern const CanIf_BusOffNotificationFctType CanIf_BusOffNotificationFctPtr;");
                outputFile.WriteLine("");
                outputFile.WriteLine("#ifdef CANIF_BASIC_CAN");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine(" CanIf_CanIfCtrlId2MappedTxBuffersConfig");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine(" \\var    CanIf_CanIfCtrlId2MappedTxBuffersConfig");
                outputFile.WriteLine(" \\brief  CAN controller configuration - mapped Tx-buffer(s).");
                outputFile.WriteLine(" \\details");
                outputFile.WriteLine("Element                          Description");
                outputFile.WriteLine("MappedTxBuffersConfigEndIdx      the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig");
                outputFile.WriteLine("MappedTxBuffersConfigStartIdx    the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig");
                outputFile.WriteLine("*/ ");
                outputFile.WriteLine("extern const CanIf_CanIfCtrlId2MappedTxBuffersConfigType CanIf_CanIfCtrlId2MappedTxBuffersConfig[CANIF_CFG_MAX_CONTROLLER];");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_CtrlModeIndicationFctPtr");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("");
                outputFile.WriteLine("extern const CanIf_CtrlModeIndicationFctType CanIf_CtrlModeIndicationFctPtr;");
                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine(" CanIf_MailBoxConfig");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_MailBoxConfig");
                outputFile.WriteLine(" \\brief  Mailbox table.");
                outputFile.WriteLine("\\details");
                outputFile.WriteLine("Element                 Description");
                outputFile.WriteLine("CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates");
                outputFile.WriteLine("PduIdFirst              \"First\" PDU mapped to mailbox.");
                outputFile.WriteLine("PduIdLast               \"Last\" PDU mapped to mailbox.");
                outputFile.WriteLine("TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig");
                outputFile.WriteLine("TxBufferHandlingType");
                outputFile.WriteLine("MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.");
                outputFile.WriteLine("*/ ");
                outputFile.WriteLine("extern const CanIf_MailBoxConfigType CanIf_MailBoxConfig[CANIF_TOTAL_NUM_OF_MAIL_BOX];");
                outputFile.WriteLine("");
                outputFile.WriteLine("#ifdef CANIF_BASIC_CAN");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine(" CanIf_MappedTxBuffersConfig");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_MappedTxBuffersConfig");
                outputFile.WriteLine("\\brief  Mapped Tx-buffer(s)");
                outputFile.WriteLine("\\details");
                outputFile.WriteLine("Element             Description");
                outputFile.WriteLine("MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig");
                outputFile.WriteLine("*/ ");
                outputFile.WriteLine("extern const CanIf_MappedTxBuffersConfigType CanIf_MappedTxBuffersConfig[CANIF_TOTAL_NUM_OF_MAILBOX_CONIGURED_TO_STORE_TX_BUFFERS];");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine(" CanIf_RxIndicationFctList");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_RxIndicationFctList");
                outputFile.WriteLine(" \\brief  Rx indication functions table.");
                outputFile.WriteLine("\\details");
                outputFile.WriteLine("Element               Description");
                outputFile.WriteLine("RxIndicationFct       Rx indication function.");
                outputFile.WriteLine("RxIndicationLayout    Layout of Rx indication function.");
                outputFile.WriteLine("*/");
                outputFile.WriteLine("extern const CanIf_RxIndicationFctListType CanIf_RxIndicationFctList[CANIF_TOTAL_RX_INIDICATION_FUNC];");
                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_RxPduConfig");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine(" \\var    CanIf_RxPduConfig");
                outputFile.WriteLine(" \\brief  Rx-PDU configuration table.");
                outputFile.WriteLine(" \\details");
                outputFile.WriteLine(" Element                   Description");
                outputFile.WriteLine(" RxPduCanId                Rx-PDU: CAN identifier.");
                outputFile.WriteLine(" RxPduMask                 Rx-PDU: CAN identifier mask.");
                outputFile.WriteLine(" UpperPduId                PDU ID defined by upper layer.");
                outputFile.WriteLine("Dlc                       Data length code.");
                outputFile.WriteLine(" RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList");
                outputFile.WriteLine("*/ ");
                outputFile.WriteLine("extern const CanIf_RxPduConfigType CanIf_RxPduConfig[CANIF_TOTAL_RX_PDU];");
                outputFile.WriteLine("");
                //outputFile.WriteLine("/**********************************************************************************************************************");
                //outputFile.WriteLine(" CanIf_TrcvModeIndicationFctPtr");
                //outputFile.WriteLine("**********************************************************************************************************************/");
                //outputFile.WriteLine("#if 0");
                //outputFile.WriteLine("extern const CanIf_TrcvModeIndicationFctType CanIf_TrcvModeIndicationFctPtr;");
                //outputFile.WriteLine("#endif");
                //outputFile.WriteLine("/**********************************************************************************************************************");
                //outputFile.WriteLine(" CanIf_TrcvToCtrlMap");
                //outputFile.WriteLine("**********************************************************************************************************************/");
                //outputFile.WriteLine("/** ");
                //outputFile.WriteLine(" \\var    CanIf_TrcvToCtrlMap");
                //outputFile.WriteLine("\\brief  Indirection table: logical transceiver index to CAN controller index.");
                //outputFile.WriteLine("*/ ");
                //outputFile.WriteLine("extern const uint8_t CanIf_TrcvToCtrlMap[CANIF_CFG_MAX_CONTROLLER];");
                outputFile.WriteLine("");
                outputFile.WriteLine("#ifdef CANIF_BASIC_CAN");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_TxBufferPrioByCanIdByteQueueConfig");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine(" \\var    CanIf_TxBufferPrioByCanIdByteQueueConfig");
                outputFile.WriteLine(" \\brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE");
                outputFile.WriteLine(" \\details");
                outputFile.WriteLine(" Element      Description");
                outputFile.WriteLine("TxBufferPrioByCanIdBaseIdx                          the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase");
                outputFile.WriteLine("TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx      the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus");
                outputFile.WriteLine(" TxBufferPrioByCanIdByteQueueMappedTxPdusLength      the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus");
                outputFile.WriteLine("TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx    the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus");
                outputFile.WriteLine("*/");
                outputFile.WriteLine("");
                outputFile.WriteLine("extern const CanIf_TxBufferPrioByCanIdByteQueueConfigType CanIf_TxBufferPrioByCanIdByteQueueConfig[CANIF_TOTAL_NUM_OF_MAILBOX_CONIGURED_TO_STORE_TX_BUFFERS];");
                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine(" CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine(" \\var    CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus");
                outputFile.WriteLine("\\brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE: Mapped Tx-PDUs");
                outputFile.WriteLine(" \\details");
                outputFile.WriteLine(" Element           Description");
                outputFile.WriteLine("TxPduConfigIdx    the index of the 1:1 relation pointing to CanIf_TxPduConfig");
                outputFile.WriteLine("*/ ");
                outputFile.WriteLine("");
                outputFile.WriteLine("extern const CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[CANIF_TOTAL_TX_BUFFER_MESSAGE];");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine(" CanIf_TxConfirmationFctList");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_TxConfirmationFctList");


                outputFile.WriteLine(" \\brief  Tx confirmation functions table.");
                outputFile.WriteLine("*/ ");
                outputFile.WriteLine("extern const CanIf_TxConfirmationFctType CanIf_TxConfirmationFctList[CANIF_TOTAL_TX_CONFIRMATION_FUNC_LIST];");
                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");


                outputFile.WriteLine(" CanIf_TxPduConfig");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");


                outputFile.WriteLine(" \\var    CanIf_TxPduConfig");


                outputFile.WriteLine(" \\brief  Tx-PDUs - configuration.");


                outputFile.WriteLine(" \\details");

                outputFile.WriteLine(" Element                     Description");
                outputFile.WriteLine("CanId                       CAN identifier (16bit / 32bit).");
                outputFile.WriteLine("UpperLayerTxPduId           Upper layer handle ID (8bit / 16bit).");
                outputFile.WriteLine("CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates");
                outputFile.WriteLine("Dlc                         Data length code.");
                outputFile.WriteLine("MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig");
                outputFile.WriteLine("TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList");
                outputFile.WriteLine("*/ ");
                outputFile.WriteLine("extern const CanIf_TxPduConfigType CanIf_TxPduConfig[CANIF_TOTAL_TX_MESSAGES];");
                outputFile.WriteLine("");
                outputFile.WriteLine("#ifdef CANIF_BASIC_CAN");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine(" CanIf_TxPduQueueIndex");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine(" \\var    CanIf_TxPduQueueIndex");
                outputFile.WriteLine(" \\brief  Indirection table: Tx-PDU handle ID to corresponding Tx buffer handle ID. NOTE: Only BasicCAN Tx-PDUs have a valid indirection into the Tx buffer.");
                outputFile.WriteLine(" \\details");
                outputFile.WriteLine(" Element       Description");
                outputFile.WriteLine("TxQueueIdx    the index of the 0:1 relation pointing to CanIf_TxQueue");
                outputFile.WriteLine("*/ ");
                outputFile.WriteLine("extern const CanIf_TxPduQueueIndexType CanIf_TxPduQueueIndex[CANIF_TOTAL_TX_MESSAGES];");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_CtrlStates");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine(" \\var    CanIf_CtrlStates");
                outputFile.WriteLine(" \\details");
                outputFile.WriteLine(" Element     Description");
                outputFile.WriteLine("CtrlMode    Controller mode.");
                outputFile.WriteLine("PduMode     PDU mode state.");
                outputFile.WriteLine("*/ ");
                outputFile.WriteLine("extern CanIf_CtrlStatesUType CanIf_CtrlStates;");
                outputFile.WriteLine("");
                outputFile.WriteLine("#ifdef CANIF_BASIC_CAN");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine(" CanIf_TxBufferPrioByCanIdBase");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_TxBufferPrioByCanIdBase");
                outputFile.WriteLine(" \\brief  Variable declaration - Tx-buffer: PRIO_BY_CANID as byte/bit-queue. Stores at least the QueueCounter.");
                outputFile.WriteLine("*/");
                outputFile.WriteLine("extern CanIf_TxBufferPrioByCanIdBaseUType CanIf_TxBufferPrioByCanIdBase;");
                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_TxQueue");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine(" \\var    CanIf_TxQueue");
                outputFile.WriteLine(" \\brief  Variable declaration - Tx byte queue.");
                outputFile.WriteLine("*/");
                outputFile.WriteLine("extern CanIf_TxQueueUType CanIf_TxQueue;");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("");
                outputFile.WriteLine("");

                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("                                                  R E V I S I O N   H I S T O R Y             ");
                outputFile.WriteLine("************************************************************************************************************************/");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  REVISION NUMBER      : V1.0.0                                                                                   ");
                outputFile.WriteLine("  REVISION DATE        : 13/01/2020                                                                               ");
                outputFile.WriteLine("  CREATED / REVISED BY : Akshay Bavalatti (akshayb@niyatainfotech.com)                                        ");
                outputFile.WriteLine("  DESCRIPTION          : Initial Version                                                                       ");
                outputFile.WriteLine("---------------------------------------------------------------------------------------------------------------------");
                outputFile.WriteLine("***********************************************************************************************************************/");

            }
        }

        private void geneRateCanIfC()
        {
            using (StreamWriter outputFile = new StreamWriter(Path.Combine(DockingManagerModelHelper.TargetOutputFolderPath, "CanIF_cfg.c")))
            {



                outputFile.WriteLine("#ifndef CANIF_CFG_C");
                outputFile.WriteLine("#define CANIF_CFG_C");
                outputFile.WriteLine("/*********************************************************************************************************************** ");
                outputFile.WriteLine(" *    DISCLAIMER                                                                                                        ");
                outputFile.WriteLine(" *   Copyright (C) 2011, 2016 Niyata Infotech Ptv. Ltd. All rights reserved.                                              ");
                outputFile.WriteLine(" ***********************************************************************************************************************/");
                outputFile.WriteLine("");
                outputFile.WriteLine("/***********************************************************************************************************************");
                outputFile.WriteLine(" * @author              Author : Akshay Bavalatti (akshayb@niyatainfotech.com)                                                                         ");
                outputFile.WriteLine(" ***********************************************************************************************************************/");
                outputFile.WriteLine("/***********************************************************************************************************************");
                outputFile.WriteLine(" *                                                F I L E  D E S C R I P T I O N                                           ");
                outputFile.WriteLine("*---------------------------------------------------------------------------------------------------------------------");
                outputFile.WriteLine(" *  @brief                                                                                                             ");
                outputFile.WriteLine("*                                                                                                                     ");
                outputFile.WriteLine(" *  File name                       : CanIF_cfg.c                                                                         ");
                outputFile.WriteLine(" *  Version                         : V1.0.0                                                                           ");
                outputFile.WriteLine("*  Micros supported                : Micro Agnostic (Independant)                                                            ");
                outputFile.WriteLine("*  Compilers supported             : XXXX                                                                           ");
                outputFile.WriteLine("*  Platforms supported             : XXXX                                                                            ");
                outputFile.WriteLine("*  Description                     : This file contains precompile configuration settings for CanIF                                ");
                outputFile.WriteLine("*                                                                                                                     ");
                outputFile.WriteLine("*                                                                                                                     ");
                outputFile.WriteLine("*  @bug                                                                                                               ");
                outputFile.WriteLine("*---------------------------------------------------------------------------------------------------------------------*/");
                outputFile.WriteLine("/**********************************************************************************************************************/");
                outputFile.WriteLine("#ifdef __cplusplus");
                outputFile.WriteLine("extern \"C\" {");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("/**********************************************************************************************************************/");
                outputFile.WriteLine("/***********************************************************************************************************************");
                outputFile.WriteLine(" *                          I N C L U D E   F I L E S");
                outputFile.WriteLine(" ***********************************************************************************************************************/");
                outputFile.WriteLine("");
                outputFile.WriteLine("# include \"CanIF_cfg.h\"");
                outputFile.WriteLine("#include \"CanMgr.h\"");
                outputFile.WriteLine("");
                outputFile.WriteLine("/***********************************************************************************************************************");
                outputFile.WriteLine(" *                          C O N F I G U R A T I O N");
                outputFile.WriteLine("***********************************************************************************************************************/");
                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_BusOffNotificationFctPtr");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/**");
                outputFile.WriteLine(" * ");
                outputFile.WriteLine(" */ ");
                outputFile.WriteLine("const CanIf_BusOffNotificationFctType CanIf_BusOffNotificationFctPtr = &CanMgr_BusoffIndication ;");
                outputFile.WriteLine("");
                outputFile.WriteLine("#ifdef CANIF_BASIC_CAN");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine(" CanIf_CanIfCtrlId2MappedTxBuffersConfig");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("\\var    CanIf_CanIfCtrlId2MappedTxBuffersConfig");
                outputFile.WriteLine("\\brief  CAN controller configuration - mapped Tx-buffer(s).");
                outputFile.WriteLine("\\details");
                outputFile.WriteLine(" Element                          Description");
                outputFile.WriteLine(" MappedTxBuffersConfigEndIdx      the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig");
                outputFile.WriteLine(" MappedTxBuffersConfigStartIdx    the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig");
                outputFile.WriteLine("*/ ");
                int totalTxBasicCanMessage = 0;
                int totalTxBacicCanMailBox = 0;
                int totalTxMessages = 0;
                int totalRxMessages = 0;
                foreach (KeyValuePair<string, string> kvp in mailBoxCanif)
                {
                    if (kvp.Value.Equals("CANIF_TxBasicCANMailbox"))
                    {

                        totalTxBacicCanMailBox++;
                        if (mailBoxMessage.ContainsKey(kvp.Key))
                        {
                            totalTxBasicCanMessage++;
                            totalTxMessages++;
                        }
                        if (mailBoxMessageMore.ContainsKey(kvp.Key))
                        {
                            totalTxBasicCanMessage += mailBoxMessageMore[kvp.Key].Count;
                            totalTxMessages += mailBoxMessageMore[kvp.Key].Count;
                        }

                    }
                    else if (kvp.Value.Equals("CANIF_TxFullCANMailbox"))
                    {
                        totalTxMessages++;
                    }
                    else if (kvp.Value.Equals("CANIF_RxBasicCANMailbox"))
                    {
                        if (mailBoxMessageRx.ContainsKey(kvp.Key))
                        {

                            totalRxMessages++;
                        }
                        if (mailBoxMessageMoreRx.ContainsKey(kvp.Key))
                        {

                            totalRxMessages += mailBoxMessageMoreRx[kvp.Key].Count;
                        }
                    }
                    else if (kvp.Value.Equals("CANIF_RxFullCANMailbox"))
                    {
                        totalRxMessages++;
                    }

                }
                outputFile.WriteLine("const CanIf_CanIfCtrlId2MappedTxBuffersConfigType CanIf_CanIfCtrlId2MappedTxBuffersConfig[CANIF_CFG_MAX_CONTROLLER] = {");
                outputFile.WriteLine(string.Format("{0} {1} {2}", "  /* Index".PadRight(40), "MappedTxBuffersConfigEndIdx".PadRight(40), "MappedTxBuffersConfigStartIdx */".PadRight(40)));
                //outputFile.WriteLine(" { /*     0 */                         " + totalTxBacicCanMailBox + "U  ,                           0U  }");
                outputFile.WriteLine(string.Format("{0} {1} {2}", " { /*0*/".PadRight(50), totalTxBacicCanMailBox + "U ,".PadRight(50), "0U  }".PadRight(60)));
                outputFile.WriteLine("};");
                outputFile.WriteLine("");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine(" CanIf_CtrlModeIndicationFctPtr");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("const CanIf_CtrlModeIndicationFctType CanIf_CtrlModeIndicationFctPtr = NULL;");


                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("CanIf_MailBoxConfig");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("\\var    CanIf_MailBoxConfig");
                outputFile.WriteLine("\\brief  Mailbox table.");
                outputFile.WriteLine("\\details");
                outputFile.WriteLine(" Element                 Description");
                outputFile.WriteLine(" CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates");
                outputFile.WriteLine("PduIdFirst              \"First\" PDU mapped to mailbox.");
                outputFile.WriteLine(" PduIdLast               \"Last\" PDU mapped to mailbox.");
                outputFile.WriteLine("TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig");
                outputFile.WriteLine("TxBufferHandlingType");
                outputFile.WriteLine("MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.");
                outputFile.WriteLine("*/ ");

                outputFile.WriteLine("const CanIf_MailBoxConfigType CanIf_MailBoxConfig[CANIF_TOTAL_NUM_OF_MAIL_BOX] = {");
                outputFile.WriteLine("   /* Index\t\t\tCtrlStatesIdx\t\t\tPduIdLast\t\t\t\t\t\t\tPduIdFirst\t\t\t\t\t\t\t\t\tTxBufferCfgIdx\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tTxBufferHandlingType\t\t\t\t\t\t\t\t\t\t\t\tMailBoxType      */         ");
                //outputFile.WriteLine(string.Format("{0} {1} {2}{3} {4} {5}{6}", "/* Index".PadRight(20),"CtrlStatesIdx".PadRight(20),"PduIdFirst".PadRight(20),"PduIdLast".PadRight(20),"TxBufferCfgIdx".PadRight(20),"TxBufferHandlingType".PadRight(20),"MailBoxType      */ ".PadRight(20)));
                int rxMessageCount = 0;
                int rxUniqId = -1;
                int txUniqId = -1;
                String column3 = "0";
                String column4 = "0";
                String column5 = "CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG";
                String column6 = "CANIF_TXBUFFER_HANDLINGTYPE_NONE";
                String column7 = "CANIF_UnusedCANMailbox";
                String comment = "Unused";
                if (mailBoxCanif.ContainsKey(lstMailConfigParentsMailBox[0]))
                {
                    if (mailBoxCanif[lstMailConfigParentsMailBox[0]].Equals("CANIF_RxBasicCANMailbox"))
                    {
                        rxMessageCount = mailBoxMessageRx.ContainsKey(lstMailConfigParentsMailBox[0]) ? 1 : 0;
                        rxMessageCount += mailBoxMessageMoreRx.ContainsKey(lstMailConfigParentsMailBox[0]) ? mailBoxMessageMoreRx[lstMailConfigParentsMailBox[0]].Count : 0;
                        rxUniqId++;
                        column4 = "" + rxUniqId;
                        comment = "RxPduID";
                        if (rxUniqId == 0)
                        {
                            column3 = rxMessageCount + rxUniqId - 1 + "";
                        }
                        else
                        {
                            column3 = rxMessageCount + rxUniqId - 1 + "";
                        }

                        rxUniqId = rxMessageCount + rxUniqId - 1;
                    }
                    if (mailBoxCanif[lstMailConfigParentsMailBox[0]].Equals("CANIF_RxFullCANMailbox"))
                    {
                        rxUniqId++;
                        column4 = "" + rxUniqId;
                        comment = "RxPduID";
                        column3 = column4;
                    }
                    if (mailBoxCanif[lstMailConfigParentsMailBox[0]].Equals("CANIF_TxBasicCANMailbox"))
                    {
                        txUniqId++;
                        column5 = "" + txUniqId + "U";
                        column6 = "CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID";
                        comment = "TxPduID";
                        column3 = "0";
                        column4 = "0";
                    }
                    if (mailBoxCanif[lstMailConfigParentsMailBox[0]].Equals("CANIF_TxFullCANMailbox"))
                    {

                        comment = "TxPduID";
                        column3 = "0";
                        column4 = "0";
                    }
                    column7 = mailBoxCanif[lstMailConfigParentsMailBox[0]];


                }

                outputFile.Write("  {  /*0 */\t\t\t\t\t0U ,\t\t\t\t\t\t" + column3 + "U  /*" + comment + "*/ ,\t\t\t" + column4 + "U  /*" + comment + " */ ,\t\t\t" + column5 + ", \t\t" + column6 + ", \t\t\t\t\t" + column7 + "  }");
                // outputFile.Write(string.Format("{0} {1} {2}{3} {4} {5}{6}", "{/* 0 */".PadRight(20),         "0U  ,".PadRight(20),           column3 + "U  /* ".PadRight(20), comment + "*/ ,  ".PadRight(20) , column4 + "U  /* ".PadRight(20), comment + " */ ,  ".PadRight(20),  column5 + "   , ".PadRight(20),  column6 + "       , ".PadRight(20), column7 + "  }".PadRight(20)));
                rxMessageCount = 0;

                for (int index = 1; index < lstMailConfigParentsMailBox.Count; index++)
                {
                    outputFile.Write(",");
                    outputFile.WriteLine();
                    column4 = "0";
                    column3 = "0";
                    column5 = "CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG";
                    column6 = "CANIF_TXBUFFER_HANDLINGTYPE_NONE";
                    column7 = "CANIF_UnusedCANMailbox";
                    comment = "Unused";
                    rxMessageCount = 0;
                    if (mailBoxCanif.ContainsKey(lstMailConfigParentsMailBox[index]))
                    {
                        if (mailBoxCanif[lstMailConfigParentsMailBox[index]].Equals("CANIF_RxBasicCANMailbox"))
                        {
                            rxMessageCount = mailBoxMessageRx.ContainsKey(lstMailConfigParentsMailBox[index]) ? 1 : 0;
                            rxMessageCount += mailBoxMessageMoreRx.ContainsKey(lstMailConfigParentsMailBox[index]) ? mailBoxMessageMoreRx[lstMailConfigParentsMailBox[index]].Count : 0;
                            rxUniqId++;
                            column4 = "" + rxUniqId;
                            comment = "RxPduID";

                            if (rxUniqId == 0)
                            {
                                column3 = rxMessageCount + rxUniqId - 1 + "";
                            }
                            else
                            {
                                column3 = rxMessageCount + rxUniqId - 1 + "";
                            }
                            rxUniqId = rxMessageCount + rxUniqId - 1;


                        }
                        if (mailBoxCanif[lstMailConfigParentsMailBox[index]].Equals("CANIF_RxFullCANMailbox"))
                        {
                            rxUniqId++;
                            column4 = "" + rxUniqId;
                            comment = "RxPduID";
                            column3 = column4;
                        }
                        if (mailBoxCanif[lstMailConfigParentsMailBox[index]].Equals("CANIF_TxBasicCANMailbox"))
                        {
                            txUniqId++;
                            column5 = "" + txUniqId + "U";
                            column6 = "CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID";
                            comment = "TxPduID";
                            column3 = "0";
                        }
                        if (mailBoxCanif[lstMailConfigParentsMailBox[index]].Equals("CANIF_TxFullCANMailbox"))
                        {

                            comment = "TxPduID";
                            column3 = "0";
                        }
                        column7 = mailBoxCanif[lstMailConfigParentsMailBox[index]];


                    }
                    if (index < 10)
                    {
                        string col5 = column5.Length > 3 ? column5 : column5 + "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
                        outputFile.Write("  {  /*" + index + " */\t\t\t\t\t0U,\t\t\t\t\t\t\t" + column3 + "U  /*" + comment + "*/ ,\t\t\t" + column4 + "U  /*" + comment + " */ ,\t\t\t" + col5 + ",\t\t" + column6 + ", \t\t\t\t\t" + column7 + "  }");
                    }
                    else
                    {
                        string col5 = column5.Length > 3 ? column5 : column5 + "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
                        outputFile.Write("  {  /*" + index + "*/\t\t\t\t\t0U,\t\t\t\t\t\t\t" + column3 + "U  /*" + comment + "*/ ,\t\t\t" + column4 + "U  /*" + comment + " */ ,\t\t\t" + col5 + ",\t\t" + column6 + ", \t\t\t\t\t" + column7 + "  }");
                    }
                    //outputFile.Write(string.Format("{0} {1} {2}{3} {4} {5}{6}", "{/*" + index + " */".PadRight(20), "0U  ,".PadRight(20), column3 + "U  /* ".PadRight(20), comment + "*/ ,  ".PadRight(20), column4 + "U  /* ".PadRight(20), comment + " */ ,  ".PadRight(20), column5 + "   , ".PadRight(20), column6 + "       , ".PadRight(20), column7 + "  }".PadRight(20)));
                }
                outputFile.WriteLine("");
                outputFile.WriteLine("};");
                outputFile.WriteLine("");
                outputFile.WriteLine("");
                outputFile.WriteLine("#ifdef CANIF_BASIC_CAN");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("CanIf_MappedTxBuffersConfig");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_MappedTxBuffersConfig");
                outputFile.WriteLine("  \\brief  Mapped Tx-buffer(s)");
                outputFile.WriteLine("  \\details");
                outputFile.WriteLine("  Element             Description");
                outputFile.WriteLine("  MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig");
                outputFile.WriteLine("*/ ");
                outputFile.WriteLine("const CanIf_MappedTxBuffersConfigType CanIf_MappedTxBuffersConfig[CANIF_TOTAL_NUM_OF_MAILBOX_CONIGURED_TO_STORE_TX_BUFFERS] = {");
                outputFile.WriteLine("      /* Index    MailBoxConfigIdx */     ");
                int lindex = -1;
                if (lstMailConfigParentsMailBox != null && lstMailConfigParentsMailBox.Count > 0)
                {
                    if (mailBoxCanif.ContainsKey(lstMailConfigParentsMailBox[0]))
                    {
                        string value = mailBoxCanif[lstMailConfigParentsMailBox[0]];
                        if (value != null && !value.Trim().Equals("") && value.Trim().Equals("CANIF_TxBasicCANMailbox"))
                        {
                            lindex++;
                            outputFile.Write(" {  /*    " + lindex + "*/        " + (0) + "U" + "   }");

                        }

                    }
                    for (int index = 1; index < lstMailConfigParentsMailBox.Count; index++)
                    {
                        if (mailBoxCanif.ContainsKey(lstMailConfigParentsMailBox[index]))
                        {
                            string value = mailBoxCanif[lstMailConfigParentsMailBox[index]];
                            if (value != null && !value.Trim().Equals("") && value.Trim().Equals("CANIF_TxBasicCANMailbox"))
                            {
                                lindex++;
                                if (lindex == 0)
                                {

                                    outputFile.Write("  { /*    " + lindex + "*/        " + (index) + "U" + "   }");
                                }
                                else
                                {

                                    outputFile.Write(",");
                                    outputFile.WriteLine("");
                                    outputFile.Write("  { /*    " + lindex + "*/        " + (index) + "U" + "   }");

                                }

                            }

                        }
                    }
                }
                outputFile.WriteLine("");
                outputFile.WriteLine("};");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_RxIndicationFctList");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_RxIndicationFctList");
                outputFile.WriteLine("  \\brief  Rx indication functions table.");
                outputFile.WriteLine("  \\details");
                outputFile.WriteLine("  Element               Description");
                outputFile.WriteLine("  RxIndicationFct       Rx indication function.");
                outputFile.WriteLine("  RxIndicationLayout    Layout of Rx indication function.");
                outputFile.WriteLine("*/");
                outputFile.WriteLine("const CanIf_RxIndicationFctListType CanIf_RxIndicationFctList[CANIF_TOTAL_RX_INIDICATION_FUNC] = {");
                outputFile.WriteLine("  /* Index                RxIndicationFct                                                RxIndicationLayout   */       ");
                outputFile.WriteLine("{ /*   0 */       { (CanIf_AdvancedRxIndicationFctType)&CanMgr_RxIndication }  ,  CanIf_AdvancedRxIndicationLayout   },");
                outputFile.WriteLine("{ /*   1 */       { NULL_PTR }                                                 ,  CanIf_NmRxIndicationLayout         },  ");
                outputFile.WriteLine("{ /*   2 */       { NULL_PTR }                                                 ,  CanIf_AdvancedRxIndicationLayout   },  ");
                outputFile.WriteLine("{ /*   3 */       { NULL_PTR }                                                 ,  CanIf_AdvancedRxIndicationLayout   },  ");
                outputFile.WriteLine("{ /*   4 */       { NULL_PTR }                                                 ,  CanIf_AdvancedRxIndicationLayout   }   ");
                outputFile.WriteLine("};");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_RxPduConfig");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_RxPduConfig");
                outputFile.WriteLine("  \\brief  Rx-PDU configuration table.");
                outputFile.WriteLine("  \\details");
                outputFile.WriteLine("  Element                   Description");
                outputFile.WriteLine("  RxPduCanId                Rx-PDU: CAN identifier.");
                outputFile.WriteLine("  RxPduMask                 Rx-PDU: CAN identifier mask.");
                outputFile.WriteLine("  UpperPduId                PDU ID defined by upper layer.");
                outputFile.WriteLine("  Dlc                       Data length code.");
                outputFile.WriteLine("  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList");
                outputFile.WriteLine("*/");


                outputFile.WriteLine("const CanIf_RxPduConfigType CanIf_RxPduConfig[CANIF_TOTAL_RX_PDU] = {");
                outputFile.WriteLine("  /*\t\tIndex\t\t\tRxPduCanId\t\t\t\t\tRxPduMask\t\t\t\t\tUpperPduId\t\t\t\t\t\t\t\t\t\tDlc\t\t\t\t\t RxIndicationFctListIdx     */           ");
                int rindex = -1;
                for (int index = 0; index < lstMailConfigParentsMailBox.Count; index++)
                {
                    if (mailBoxCanif.ContainsKey(lstMailConfigParentsMailBox[index]) && (mailBoxCanif[lstMailConfigParentsMailBox[index]].Equals("CANIF_RxBasicCANMailbox") || mailBoxCanif[lstMailConfigParentsMailBox[index]].Equals("CANIF_RxFullCANMailbox")))
                    {
                        if (mailBoxFrameIdRx.ContainsKey(lstMailConfigParentsMailBox[index]))
                        {
                            rindex++;
                            string canid = mailBoxFrameIdRx.ContainsKey(lstMailConfigParentsMailBox[index]) ? mailBoxFrameIdRx[lstMailConfigParentsMailBox[index]] : "0x000";
                            string maskValue = mailBoxMaskValueRx.ContainsKey(lstMailConfigParentsMailBox[index]) ? mailBoxMaskValueRx[lstMailConfigParentsMailBox[index]] : "0x000";
                            string dlc = mailBoxDLCRx.ContainsKey(lstMailConfigParentsMailBox[index]) ? mailBoxDLCRx[lstMailConfigParentsMailBox[index]] + "U" : "0U";
                            // string mailboxnumber = "" + lstMailConfigParentsMailBox[index];
                            //   string mailboxnumber =""+ (index+1) ;
                            string mailboxnumber = "0U";
                            string upperPduId = mailBoxMessageRx.ContainsKey(lstMailConfigParentsMailBox[index]) ? "(PduIdType)" + SplitCamelCase(mailBoxMessageRx[lstMailConfigParentsMailBox[index]]).ToUpper() : "CANMGR_0x0000";

                            if (rindex == 0)
                            {
                                outputFile.Write("{/*\t\t" + rindex + "*/\t\t\t\t\t" + canid + "U,\t\t\t\t\t  " + maskValue + "U,\t\t\t\t\t " + upperPduId + ",\t\t\t\t\t" + dlc + ",\t\t\t\t\t\t\t " + mailboxnumber + "  } ");
                            }
                            else
                            {
                                outputFile.Write(",");
                                outputFile.WriteLine();
                                outputFile.Write("{/*\t\t" + rindex + "*/\t\t\t\t\t" + canid + "U,\t\t\t\t\t  " + maskValue + "U,\t\t\t\t\t " + upperPduId + ",\t\t\t\t\t" + dlc + ",\t\t\t\t\t\t\t " + mailboxnumber + "  }");
                            }
                        }
                        if (mailBoxFrameIdMoreRx.ContainsKey(lstMailConfigParentsMailBox[index]))
                        {
                            List<string> canids = mailBoxFrameIdMoreRx[lstMailConfigParentsMailBox[index]];
                            for (int inds = 0; inds < canids.Count; inds++)
                            {
                                rindex++;
                                string canid = mailBoxFrameIdMoreRx.ContainsKey(lstMailConfigParentsMailBox[index]) ? mailBoxFrameIdMoreRx[lstMailConfigParentsMailBox[index]][inds] : "0x000";
                                string maskValue = mailBoxMaskValueMoreRx.ContainsKey(lstMailConfigParentsMailBox[index]) ? mailBoxMaskValueMoreRx[lstMailConfigParentsMailBox[index]][inds] : "0x000";
                                string dlc = mailBoxDLCMoreRx.ContainsKey(lstMailConfigParentsMailBox[index]) ? mailBoxDLCMoreRx[lstMailConfigParentsMailBox[index]][inds] + "u" : "0u";
                                //string mailboxnumber = "" + lstMailConfigParentsMailBox[index];
                                //  string mailboxnumber = "" + index + 1;
                                string mailboxnumber = "0U";

                                string upperPduId = mailBoxMessageMoreRx.ContainsKey(lstMailConfigParentsMailBox[index]) ? "(PduIdType)" + SplitCamelCase(mailBoxMessageMoreRx[lstMailConfigParentsMailBox[index]][inds]).ToUpper() : "CANMGR_0x0000";

                                if (rindex == 0)
                                {
                                    outputFile.WriteLine("{/*\t\t" + rindex + "*/\t\t\t\t\t" + canid + "U,\t\t\t\t\t  " + maskValue + "U,\t\t\t\t\t " + upperPduId + ",\t\t\t\t\t" + dlc + ",\t\t\t\t\t\t\t " + mailboxnumber + "   }");
                                }
                                else
                                {
                                    outputFile.Write(",");
                                    outputFile.WriteLine();
                                    outputFile.Write("{/*\t\t" + rindex + "*/\t\t\t\t\t" + canid + "U,\t\t\t\t\t  " + maskValue + "U,\t\t\t\t\t " + upperPduId + ",\t\t\t\t\t" + dlc + ",\t\t\t\t\t\t\t " + mailboxnumber + "   }");
                                }
                            }
                        }
                    }
                }
                outputFile.WriteLine("};");
                //outputFile.WriteLine("/**********************************************************************************************************************");
                //outputFile.WriteLine("  CanIf_TrcvModeIndicationFctPtr");
                //outputFile.WriteLine("#if 0");
                //outputFile.WriteLine("const CanIf_TrcvModeIndicationFctType CanIf_TrcvModeIndicationFctPtr = NULL;");
                //outputFile.WriteLine("#endif");
                //outputFile.WriteLine("/**********************************************************************************************************************");
                //outputFile.WriteLine("  CanIf_TrcvToCtrlMap");
                //outputFile.WriteLine("**********************************************************************************************************************/");
                //outputFile.WriteLine("/** ");
                //outputFile.WriteLine("  \\var    CanIf_TrcvToCtrlMap");
                //outputFile.WriteLine("  \\brief  Indirection table: logical transceiver index to CAN controller index.");
                //outputFile.WriteLine("*/ ");
                //outputFile.WriteLine("const uint8_t CanIf_TrcvToCtrlMap[CANIF_CFG_MAX_CONTROLLER] = {");
                //outputFile.WriteLine("  /* Index     TrcvToCtrlMap ");
                //outputFile.WriteLine("  /*     0 */             0U  /* CAN controller handle ID (upper) */");
                //outputFile.WriteLine("};");
                outputFile.WriteLine("");
                outputFile.WriteLine("#ifdef CANIF_BASIC_CAN");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("   CanIf_TxBufferPrioByCanIdByteQueueConfig");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_TxBufferPrioByCanIdByteQueueConfig");
                outputFile.WriteLine("  \\brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE");
                outputFile.WriteLine("  \\details");
                outputFile.WriteLine("  Element                                             Description");
                outputFile.WriteLine("  TxBufferPrioByCanIdBaseIdx                          the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase");
                outputFile.WriteLine("  TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx      the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus");
                outputFile.WriteLine("  TxBufferPrioByCanIdByteQueueMappedTxPdusLength      the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus");
                outputFile.WriteLine("  TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx    the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus");
                outputFile.WriteLine("*/");
                outputFile.WriteLine("");
                outputFile.WriteLine("const CanIf_TxBufferPrioByCanIdByteQueueConfigType CanIf_TxBufferPrioByCanIdByteQueueConfig[CANIF_TOTAL_NUM_OF_MAILBOX_CONIGURED_TO_STORE_TX_BUFFERS] = {");
                outputFile.WriteLine("  /* Index    TxBufferPrioByCanIdBaseIdx       TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx    TxBufferPrioByCanIdByteQueueMappedTxPdusLength    TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx  */ ");
                int ind = 0;
                int txBsic = -1;
                if (mailBoxCanif != null && mailBoxCanif.Count > 0)
                {
                    int temp = 0;
                    foreach (KeyValuePair<string, string> kvp in mailBoxCanif)
                    {
                        if (kvp.Value.Equals("CANIF_TxBasicCANMailbox"))
                        {
                            int totlMsg = mailBoxMessageMore.ContainsKey(kvp.Key) ? mailBoxMessageMore[kvp.Key].Count : 0;
                            totlMsg += mailBoxMessage.ContainsKey(kvp.Key) ? 1 : 0;
                            if (ind == 0)
                            {
                                outputFile.Write(" {  /*    " + ind + "*/                                           " + (++txBsic) + "U,                            " + ((temp) + (totlMsg)) + "U,                       " + (totlMsg) + "U,                             " + (temp) + "U   }  ");
                            }
                            else
                            {
                                outputFile.Write(",");
                                outputFile.WriteLine();
                                outputFile.Write(" {  /*    " + ind + "*/                                           " + (++txBsic) + "U,                            " + ((temp) + (totlMsg)) + "U,                     " + (totlMsg) + "U,                            " + (temp) + "U   }  ");
                            }
                            ind++;
                            temp += (totlMsg);
                        }
                    }
                }
                outputFile.WriteLine();
                outputFile.WriteLine("};");
                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus");
                outputFile.WriteLine("  \\brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE: Mapped Tx-PDUs");
                outputFile.WriteLine("  \\details");
                outputFile.WriteLine("  Element           Description");
                outputFile.WriteLine("  TxPduConfigIdx    the index of the 1:1 relation pointing to CanIf_TxPduConfig");
                outputFile.WriteLine("*/ ");
                outputFile.WriteLine("");
                outputFile.WriteLine("const CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[CANIF_TOTAL_TX_BUFFER_MESSAGE] = {");
                outputFile.WriteLine("  /* Index    TxPduConfigIdx */");
                int txBasicIndex = 0;
                int llindex = 0;
                for (int index = 0; index < lstMailConfigParentsMailBox.Count; index++)
                {
                    if (mailBoxCanif.ContainsKey(lstMailConfigParentsMailBox[index]))
                    {
                        if (mailBoxCanif[lstMailConfigParentsMailBox[index]].Equals("CANIF_TxBasicCANMailbox"))
                        {
                            if (mailBoxMessage.ContainsKey(lstMailConfigParentsMailBox[index]))
                            {

                                if (txBasicIndex == 0)
                                {
                                    outputFile.Write("{/*     " + txBasicIndex + " */      " + llindex + "U     }");
                                }
                                else
                                {
                                    outputFile.Write(",");
                                    outputFile.WriteLine();
                                    outputFile.Write("{/*     " + txBasicIndex + " */      " + llindex + "U     }");
                                }
                                txBasicIndex++;
                                llindex++;
                            }
                            if (mailBoxMessageMore.ContainsKey(lstMailConfigParentsMailBox[index]))
                            {
                                foreach (String val in mailBoxMessageMore[lstMailConfigParentsMailBox[index]])
                                {

                                    if (txBasicIndex == 0)
                                    {
                                        outputFile.Write("{/*     " + txBasicIndex + " */      " + llindex + "U     }");
                                    }
                                    else
                                    {
                                        outputFile.Write(",");
                                        outputFile.WriteLine();
                                        outputFile.Write("{/*     " + txBasicIndex + " */      " + llindex + "U     }");
                                    }
                                    txBasicIndex++;
                                    llindex++;
                                }
                            }
                        }
                        else if (mailBoxCanif[lstMailConfigParentsMailBox[index]].Equals("CANIF_TxFullCANMailbox"))
                        {
                            llindex++;


                        }
                    }
                }
                outputFile.WriteLine("");
                outputFile.WriteLine("};");
                outputFile.WriteLine("");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_TxConfirmationFctList");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_TxConfirmationFctList");
                outputFile.WriteLine("  \\brief  Tx confirmation functions table.");
                outputFile.WriteLine("*/ ");
                outputFile.WriteLine("const CanIf_TxConfirmationFctType CanIf_TxConfirmationFctList[CANIF_TOTAL_TX_CONFIRMATION_FUNC_LIST] = {");
                outputFile.WriteLine("  /* Index     TxConfirmationFctList    Referable Keys */ ");
                outputFile.WriteLine("  /*     0 */ NULL_PTR ,");
                outputFile.WriteLine("  /*     1 */ NULL_PTR,");
                outputFile.WriteLine("  /*     2 */ NULL_PTR,");
                outputFile.WriteLine("  /*     3 */ (CanIf_TxConfirmationFctType)&CanMgr_TxConfirmation,");
                outputFile.WriteLine("  /*     4 */ NULL_PTR");
                outputFile.WriteLine("};");
                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_TxPduConfig");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_TxPduConfig");
                outputFile.WriteLine("  \\brief  Tx-PDUs - configuration.");
                outputFile.WriteLine("   \\details");
                outputFile.WriteLine("  Element                     Description");
                outputFile.WriteLine("  CanId                       CAN identifier (16bit / 32bit).");
                outputFile.WriteLine("  UpperLayerTxPduId           Upper layer handle ID (8bit / 16bit).");
                outputFile.WriteLine("   CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates");
                outputFile.WriteLine("  Dlc                         Data length code.");
                outputFile.WriteLine("  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig");
                outputFile.WriteLine("  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList");
                outputFile.WriteLine("*/ ");
                outputFile.WriteLine("const CanIf_TxPduConfigType CanIf_TxPduConfig[CANIF_TOTAL_TX_MESSAGES] = {");
                outputFile.WriteLine("  /*\t\tIndex\t\t\t\tCanId\t\t\t\t\t\t\t\tTxPduMask\t\t\t\t\t\t\t\tUpperLayerTxPduId\t\t\t\t\t\t\t\tCtrlStatesIdx\t\t\t\tDlc\t\ttMailBoxConfigIdx\t\tTxConfirmationFctListIdx    */");
                int lind = 0;
                for (int index = 0; index < lstMailConfigParentsMailBox.Count; index++)
                {
                    if (mailBoxCanif.ContainsKey(lstMailConfigParentsMailBox[index]))
                    {
                        if (mailBoxCanif[lstMailConfigParentsMailBox[index]].Equals("CANIF_TxBasicCANMailbox") || mailBoxCanif[lstMailConfigParentsMailBox[index]].Equals("CANIF_TxFullCANMailbox"))
                        {
                            if (mailBoxFrameId.ContainsKey(lstMailConfigParentsMailBox[index]))
                            {
                                string canid = mailBoxFrameId.ContainsKey(lstMailConfigParentsMailBox[index]) ? mailBoxFrameId[lstMailConfigParentsMailBox[index]] : "0x0000";
                                // string maskValue = mailBoxMaskValue.ContainsKey(lstMailConfigParentsMailBox[index]) ? mailBoxMaskValue[lstMailConfigParentsMailBox[index]] : "0x0000";
                                string CtrlStatesIdx = "0";
                                string dlc = mailBoxDLC.ContainsKey(lstMailConfigParentsMailBox[index]) ? mailBoxDLC[lstMailConfigParentsMailBox[index]] + "U" : "0U";
                                string upperPduId = mailBoxMessage.ContainsKey(lstMailConfigParentsMailBox[index]) ? "(PduIdType)" + SplitCamelCase(mailBoxMessage[lstMailConfigParentsMailBox[index]]).ToUpper() : "CANMGR_0x0000"; ;
                                string maskvalue = mailBoxMaskValue.ContainsKey(lstMailConfigParentsMailBox[index]) ? mailBoxMaskValue[lstMailConfigParentsMailBox[index]] + "U" : "0U";
                                String rxIndicationFctListIdx = "3";
                                string mailBoxNumber = index + "U";
                                if (lind == 0)
                                {
                                    outputFile.Write("{\t\t/*\t\t" + lind + "*/\t\t\t\t" + canid + "U,\t\t\t\t\t\t\t\t" + maskvalue + ",\t\t\t\t\t\t\t\t" + upperPduId + ",\t\t\t\t\t\t\t\t" + CtrlStatesIdx + "U,\t\t\t\t\t\t\t" + dlc + ",\t\t\t\t" + mailBoxNumber + ",\t\t\t\t\t\t\t\t\t\t" + rxIndicationFctListIdx + "U\t\t\t\t\t\t\t\t\t\t} ");
                                }
                                else
                                {
                                    outputFile.Write(",");
                                    outputFile.WriteLine();
                                    outputFile.Write("{\t\t/*\t\t" + lind + "*/\t\t\t\t" + canid + "U,\t\t\t\t\t\t\t\t" + maskvalue + ",\t\t\t\t\t\t\t\t" + upperPduId + ",\t\t\t\t\t\t\t\t" + CtrlStatesIdx + "U,\t\t\t\t\t\t\t" + dlc + ",\t\t\t\t" + mailBoxNumber + ",\t\t\t\t\t\t\t\t\t\t" + rxIndicationFctListIdx + "U\t\t\t\t\t\t\t\t\t\t} ");
                                }
                                lind++;
                            }
                            if (mailBoxCanif[lstMailConfigParentsMailBox[index]].Equals("CANIF_TxBasicCANMailbox") && mailBoxMessageMore.ContainsKey(lstMailConfigParentsMailBox[index]))
                            {
                                string mailBoxNumber = index + "U";
                                List<String> lmsgs = mailBoxMessageMore[lstMailConfigParentsMailBox[index]];
                                List<String> lmsgsMaskValue = mailBoxMaskValueMore[lstMailConfigParentsMailBox[index]];
                                List<String> lfid = mailBoxFrameIdMore.ContainsKey(lstMailConfigParentsMailBox[index]) ? mailBoxFrameIdMore[lstMailConfigParentsMailBox[index]] : null;
                                List<String> lmsvalue = mailBoxMaskValueMore.ContainsKey(lstMailConfigParentsMailBox[index]) ? mailBoxMaskValueMore[lstMailConfigParentsMailBox[index]] : null;
                                List<String> ldlc = mailBoxDLCMore.ContainsKey(lstMailConfigParentsMailBox[index]) ? mailBoxDLCMore[lstMailConfigParentsMailBox[index]] : null;
                                if (lmsgs != null)
                                {
                                    for (int lindx = 0; lindx < lmsgs.Count; lindx++)
                                    {

                                        String canid = (lfid != null && lindx < lfid.Count) ? lfid[lindx] : "0x0000";
                                        // String   maskValue = (lmsvalue != null && lindx < lmsvalue.Count) ? lmsvalue[lindx] : "0x0000";
                                        String CtrlStatesIdx = "0";
                                        string dlc = (ldlc != null && lindx < ldlc.Count) ? ldlc[lindx] + "U" : "0U";
                                        string upperPduId = "(PduIdType)" + SplitCamelCase(lmsgs[lindx]).ToUpper();
                                        int rxIndicationFctListIdx = 3;
                                        string maskvalue = (lmsgsMaskValue != null && lindx < lmsgsMaskValue.Count) ? lmsgsMaskValue[lindx] + "U" : "0U";

                                        if (lind == 0)
                                        {
                                            outputFile.Write("{\t\t/*\t\t" + lind + "*/\t\t\t\t" + canid + "U,\t\t\t\t\t\t\t\t" + maskvalue + ",\t\t\t\t\t\t\t\t" + upperPduId + ",\t\t\t\t\t\t\t\t" + CtrlStatesIdx + "U,\t\t\t\t\t\t\t" + dlc + ",\t\t\t\t" + mailBoxNumber + ",\t\t\t\t\t\t\t\t\t\t" + rxIndicationFctListIdx + "U\t\t\t\t\t\t\t\t\t\t} ");
                                        }
                                        else
                                        {
                                            outputFile.Write(",");
                                            outputFile.WriteLine();
                                            outputFile.Write("{\t\t/*\t\t" + lind + "*/\t\t\t\t" + canid + "U,\t\t\t\t\t\t\t\t" + maskvalue + ",\t\t\t\t\t\t\t\t" + upperPduId + ",\t\t\t\t\t\t\t\t" + CtrlStatesIdx + "U,\t\t\t\t\t\t\t" + dlc + ",\t\t\t\t" + mailBoxNumber + ",\t\t\t\t\t\t\t\t\t\t" + rxIndicationFctListIdx + "U\t\t\t\t\t\t\t\t\t\t } ");
                                        }

                                        lind++;
                                    }
                                }


                            }
                        }
                    }



                }
                outputFile.WriteLine("");
                outputFile.WriteLine("};");
                outputFile.WriteLine("#ifdef CANIF_BASIC_CAN");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_TxPduQueueIndex");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_TxPduQueueIndex");
                outputFile.WriteLine("  \\brief  Indirection table: Tx-PDU handle ID to corresponding Tx buffer handle ID. NOTE: Only BasicCAN Tx-PDUs have a valid indirection into the Tx buffer.");
                outputFile.WriteLine("  \\details");
                outputFile.WriteLine("  Element       Description");
                outputFile.WriteLine("  TxQueueIdx    the index of the 0:1 relation pointing to CanIf_TxQueue");
                outputFile.WriteLine("*/");
                outputFile.WriteLine("const CanIf_TxPduQueueIndexType CanIf_TxPduQueueIndex[CANIF_TOTAL_TX_MESSAGES] = {");
                outputFile.WriteLine("  /* Index    TxQueueIdx                              */      ");
                int bindex = -1;
                int btxindex = -1;
                for (int index = 0; index < lstMailConfigParentsMailBox.Count; index++)
                {
                    if (mailBoxCanif.ContainsKey(lstMailConfigParentsMailBox[index]))
                    {
                        if (mailBoxCanif[lstMailConfigParentsMailBox[index]].Equals("CANIF_TxBasicCANMailbox"))
                        {
                            if (mailBoxMessage.ContainsKey(lstMailConfigParentsMailBox[index]))
                            {
                                bindex++;
                                btxindex++;
                                if (bindex == 0)
                                {
                                    outputFile.Write("{/*     " + bindex + " */      " + btxindex + "     }");
                                }
                                else
                                {
                                    outputFile.Write(",");
                                    outputFile.WriteLine();
                                    outputFile.Write("{/*     " + bindex + " */      " + btxindex + "     }");
                                }
                            }
                            if (mailBoxMessageMore.ContainsKey(lstMailConfigParentsMailBox[index]))
                            {
                                foreach (String val in mailBoxMessageMore[lstMailConfigParentsMailBox[index]])
                                {
                                    bindex++;
                                    btxindex++;
                                    if (bindex == 0)
                                    {
                                        outputFile.Write("{/*     " + bindex + " */      " + btxindex + "     }");
                                    }
                                    else
                                    {
                                        outputFile.Write(",");
                                        outputFile.WriteLine();
                                        outputFile.Write("{/*     " + bindex + " */      " + btxindex + "     }");
                                    }
                                }
                            }
                        }
                        else if (mailBoxCanif[lstMailConfigParentsMailBox[index]].Equals("CANIF_TxFullCANMailbox"))
                        {
                            bindex++;

                            if (bindex == 0)
                            {
                                outputFile.Write("{/*     " + bindex + " */      " + "CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX" + "     }");
                            }
                            else
                            {
                                outputFile.Write(",");
                                outputFile.WriteLine();
                                outputFile.Write("{/*     " + bindex + " */      " + "CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX" + "     } ");
                            }
                        }
                    }
                }
                outputFile.WriteLine("};");
                outputFile.WriteLine("");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_CtrlStates");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_CtrlStates");
                outputFile.WriteLine("  \\details");
                outputFile.WriteLine("  Element     Description");
                outputFile.WriteLine("  CtrlMode    Controller mode.");
                outputFile.WriteLine("  PduMode     PDU mode state.");
                outputFile.WriteLine("*/ ");
                outputFile.WriteLine("CanIf_CtrlStatesUType CanIf_CtrlStates;  ");
                //outputFile.WriteLine("  /* Index        Referable Keys  */");
                //outputFile.WriteLine("  /*     0 */  /* [/ActiveEcuC/CanIf/Can/CT_Hyundai_e738e4b7] */");
                //outputFile.WriteLine("  /*     1 */  /* [/ActiveEcuC/CanIf/Can/CT_CAN00_e738e4b7] */");
                outputFile.WriteLine("#ifdef CANIF_BASIC_CAN");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_TxBufferPrioByCanIdBase");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_TxBufferPrioByCanIdBase");
                outputFile.WriteLine("  \\brief  Variable declaration - Tx-buffer: PRIO_BY_CANID as byte/bit-queue. Stores at least the QueueCounter.");
                outputFile.WriteLine("*/");
                outputFile.WriteLine("");
                outputFile.WriteLine("CanIf_TxBufferPrioByCanIdBaseUType CanIf_TxBufferPrioByCanIdBase;  ");
                //outputFile.WriteLine("  /* Index        Referable Keys  */");
                //outputFile.WriteLine("  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_CLU11] */");
                //outputFile.WriteLine("  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_NM_CLU] */");
                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("  CanIf_TxQueue");
                outputFile.WriteLine("**********************************************************************************************************************/");
                outputFile.WriteLine("/** ");
                outputFile.WriteLine("  \\var    CanIf_TxQueue");
                outputFile.WriteLine("  \\brief  Variable declaration - Tx byte queue.");
                outputFile.WriteLine("*/");
                outputFile.WriteLine("CanIf_TxQueueUType CanIf_TxQueue;  ");
                //outputFile.WriteLine("  /* Index        Referable Keys  */");
                //outputFile.WriteLine("  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CLU11_oHyundai_Tx_3abd61be] */");
                //outputFile.WriteLine("  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/NM_CLU_oCAN00_Tx_3abd61be] */");
                outputFile.WriteLine("");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("");
                outputFile.WriteLine("#endif");
                outputFile.WriteLine("");
                outputFile.WriteLine("/**********************************************************************************************************************");
                outputFile.WriteLine("                                          R E V I S I O N   H I S T O R Y                                        ");
                outputFile.WriteLine("***********************************************************************************************************************");
                outputFile.WriteLine("***********************************************************************************************************************");
                outputFile.WriteLine("");
                outputFile.WriteLine("");
                outputFile.WriteLine("");
                outputFile.WriteLine("");
                outputFile.WriteLine("***********************************************************************************************************************/");
                outputFile.WriteLine("");


            }
        }

        private void GenerateBtn_Click(object sender, RoutedEventArgs e)
        {
            bool isCantoolsConfigGenerated = false;
            bool isConfigGenerated = false;
            string Message = string.Empty;
            if (!File.Exists(DockingManagerModelHelper.TargetInputFolderPath + "\\CAN_Driver_cfg.h"))
            {
                isConfigGenerated = false;
                //MessageBox.Show("Please Upload Corresponding Config.h file for the uploaded ARXML file at following location..." + DockingManagerModelHelper.TargetInputFolderPath);
            }
            else
            {
                GetUpdatedValuesForConfigGeneration();
                DockingManagerModelHelper.UpdateARXML();
                DockingManagerModelHelper.GenerateConfigFile();
                isConfigGenerated = true;
            }
            if (File.Exists(DockingManagerModelHelper.TargetInputFolderPath + "\\Sample_DB.dbc"))
            {
                DockingManagerModelHelper.GenerateCantoolsConfigurations();
                isCantoolsConfigGenerated = true;
            }
            else
            {
                isCantoolsConfigGenerated = false;
                //MessageBox.Show("Please Upload .DBC file to Generate Cantools Config Files at following location..." + DockingManagerModelHelper.TargetInputFolderPath);
            }

            if (isCantoolsConfigGenerated && isConfigGenerated)
            {
                Message = "Output Files Generated and Saved Successfully at following path : " + DockingManagerModelHelper.TargetOutputFolderPath;
            }
            else if (isConfigGenerated && !isCantoolsConfigGenerated)
            {
                Message = "1) Config File Generated Successfully at Following Location..." + DockingManagerModelHelper.TargetInputFolderPath + Environment.NewLine + Environment.NewLine
                    + "2) Cantools Confing Could not be Generated, Please Upload .DBC file to Generate Cantools Config Files at following location..." + DockingManagerModelHelper.TargetInputFolderPath;
            }
            else if (!isConfigGenerated && isCantoolsConfigGenerated)
            {
                Message = "1) Config file Could not be generated, Please upload corresponding config.h file for the uploaded ARXML file at following location..." + DockingManagerModelHelper.TargetInputFolderPath + Environment.NewLine + Environment.NewLine
                   + "2) Cantools confing files generated at following location..." + DockingManagerModelHelper.TargetInputFolderPath;
            }
            else if (!isConfigGenerated && !isCantoolsConfigGenerated)
            {
                Message = "Output files not generated... Please check and upload corresponding Config.H and .DBC Files at following location..." + DockingManagerModelHelper.TargetInputFolderPath;
            }
            MessageBox.Show(Message);
        }

        private void ValidateBtn_Click(object sender, RoutedEventArgs e)
        {
            // For now, we are not doing any extra validation
            // All validations are done real time, during the user input itself.
            // Just return success. Everyone is happy :)
            MessageBox.Show("Validation of user entered values successful");
        }

        private List<string> GetValuesFromArxml(AUTOSAR objAutoSAR, string modulename, string node)
        {
            var currentmodule = objAutoSAR.ARPACKAGES.Where(x => x.SHORTNAME.ToString().ToLower().Equals(modulename.ToLower())).FirstOrDefault();

            var objSupportedValues = from Pkgs in currentmodule.ELEMENTS.ECUCMODULECONFIGURATIONVALUES.CONTAINERS.SUBCONTAINERS[0].SUBCONTAINERS
                                     where Pkgs.SHORTNAME.Equals(node, StringComparison.OrdinalIgnoreCase)
                                     select Pkgs.PARAMETERVALUES.SUPPORTEDVALUES.ToList();
            var lst = objSupportedValues.ToList();

            List<string> resultList = new List<string>();
            if (lst.Count > 0)
            {
                foreach (string itm in lst[0])
                {
                    resultList.Add(Convert.ToString(itm));
                }
            }
            return resultList;
        }


        private void wsTreeView_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            var sItem = (sender as TreeViewAdv).SelectedItem as TreeViewItemAdv;

            DockingManagerModelHelper.ModuleName = sItem.Header.ToString();

            // Save the changes in the UI elements
            var currentGrid = SpForDynamicGrid.Children.OfType<Grid>().Where(x => x.Name.ToLower() == DockingManagerModelHelper.ModuleName.ToLower()).FirstOrDefault();
            var currPackage = DockingManagerModelHelper.Configuration.ARPACKAGES.Where(x => x.SHORTNAME.ToLower() == DockingManagerModelHelper.ModuleName.ToLower()).FirstOrDefault();

            if ((currentGrid != null) && (currPackage != null))
            {
                // Get the config objects for this module
                foreach (var child in currentGrid.Children)
                {
                    // The below if condition is needed to weed out Labels. They can't be updated
                    if (!(child.GetType().FullName.Equals("System.Windows.Controls.TextBlock")))
                    {
                        string tempName = "";
                        string tempValue = "";

                        switch (child.GetType().Name.ToLower())
                        {
                            case "textbox":
                                var c1 = child as System.Windows.Controls.TextBox;
                                tempName = c1.Name.Remove(c1.Name.Length - 4);
                                tempValue = c1.Text;
                                break;
                            case "checkbox":
                                var c2 = child as System.Windows.Controls.CheckBox;
                                tempName = c2.Name.Remove(c2.Name.Length - 4);
                                tempValue = (bool)c2.IsChecked ? "ENABLE" : "DISABLE";
                                break;
                            case "combobox":
                                var c3 = child as System.Windows.Controls.ComboBox;
                                tempName = c3.Name.Remove(c3.Name.Length - 4);
                                tempValue = c3.SelectedValue.ToString();
                                break;
                        }

                        var currObj = currPackage.ELEMENTS.ECUCMODULECONFIGURATIONVALUES.CONTAINERS.SUBCONTAINERS[0].SUBCONTAINERS
                            .Where(x => ((x.PARAMETERVALUES != null) && (x.PARAMETERVALUES.DEFINITIONREF.Value == tempName))).FirstOrDefault();

                        if (currObj != null)
                            currObj.PARAMETERVALUES.VALUE.Value = tempValue;
                    }
                }
            }

            CreateDynamicWPFGridForModule();
        }

        private void GetUpdatedValuesForConfigGeneration()
        {
            Grid grd = SpForDynamicGrid.Children[0] as Grid;
            string key = string.Empty;
            for (int i = 0; i < grd.Children.Count; i++)
            {
                if (grd.Children[i].GetType() == typeof(TextBlock))
                {
                    key = (grd.Children[i] as TextBlock).Text;
                }
                if (i + 1 < grd.Children.Count && grd.Children[i + 1].GetType() == typeof(ComboBox))
                {

                    try
                    {
                        string value = (grd.Children[i + 1] as ComboBox).SelectedValue.ToString();
                        UpdateObject(key, value);
                    }
                    catch (Exception e)
                    {
                        Logger.Log.Instance.Trace(e.Message);
                    }
                }
                if (i + 1 < grd.Children.Count && grd.Children[i + 1].GetType() == typeof(TextBox))
                {
                    string value = (grd.Children[i + 1] as TextBox).Text.ToString();
                    UpdateObject(key, value);
                }
                if (i + 1 < grd.Children.Count && grd.Children[i + 1].GetType() == typeof(CheckBox))
                {
                    string value = (bool)(grd.Children[i + 1] as CheckBox).IsChecked ? "ENABLE" : "DISABLE";
                    UpdateObject(key, value);
                }
            }
        }

        public void UpdateObject(string key, string value)
        {
            bool isObjectFound = false;

            var currentPackage = DockingManagerModelHelper.Configuration.ARPACKAGES.Where(x => String.Equals(x.SHORTNAME.ToString().ToLower(), DockingManagerModelHelper.ModuleName.ToLower())).FirstOrDefault();

            for (int j = 0; j < currentPackage.ELEMENTS.ECUCMODULECONFIGURATIONVALUES.CONTAINERS.SUBCONTAINERS.Length; j++)
            {
                var currentConfigParamGrandParent = currentPackage.ELEMENTS.ECUCMODULECONFIGURATIONVALUES.CONTAINERS.SUBCONTAINERS[j];
                //TODO: Need to refine below code to accept only filtered object.
                for (int k = 0; k < currentConfigParamGrandParent.SUBCONTAINERS.Length; k++)
                {
                    List<string> lstSupportedValues = new List<string>();
                    string strControlType = string.Empty;
                    var currentConfigParamParent = currentConfigParamGrandParent.SUBCONTAINERS[k];
                    if (currentConfigParamParent.PARAMETERVALUES != null && currentConfigParamParent.PARAMETERVALUES.DEFINITIONREF.Value.Equals(key, StringComparison.OrdinalIgnoreCase))
                    {
                        currentConfigParamParent.PARAMETERVALUES.VALUE.Value = value;
                        break;
                    }


                    // foreach (var currentConfigParamChild in currentConfigParamParent.SUBCONTAINERS)
                    for (int i = 0; i < currentConfigParamParent.SUBCONTAINERS.Length; i++)
                    {
                        if (currentConfigParamParent.SUBCONTAINERS[i].PARAMETERVALUES.DEFINITIONREF.Value.Equals(key, StringComparison.OrdinalIgnoreCase))
                        {
                            currentConfigParamParent.SUBCONTAINERS[i].PARAMETERVALUES.VALUE.Value = value;
                            isObjectFound = true;
                            break;
                        }
                    }
                    // if obj found, break out of all loops
                    if (isObjectFound) break;
                }
                // if obj found, break out of all loops
                if (isObjectFound) break;
            }
        }

        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUE RetrieveConfigParamObject(string key)
        {

            bool isObjectFound = false;
            AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUE obj = null;

            var currentPackage = DockingManagerModelHelper.Configuration.ARPACKAGES.Where(x => String.Equals(x.SHORTNAME.ToString().ToLower(), DockingManagerModelHelper.ModuleName.ToLower())).FirstOrDefault();

            for (int j = 0; j < currentPackage.ELEMENTS.ECUCMODULECONFIGURATIONVALUES.CONTAINERS.SUBCONTAINERS.Length; j++)
            {
                var currentConfigParamGrandParent = currentPackage.ELEMENTS.ECUCMODULECONFIGURATIONVALUES.CONTAINERS.SUBCONTAINERS[j];

                //TODO: Need to refine below code to accept only filtered object.
                for (int k = 0; k < currentConfigParamGrandParent.SUBCONTAINERS.Length; k++)
                {
                    List<string> lstSupportedValues = new List<string>();
                    string strControlType = string.Empty;
                    var currentConfigParamParent = currentConfigParamGrandParent.SUBCONTAINERS[k];

                    // foreach (var currentConfigParamChild in currentConfigParamParent.SUBCONTAINERS)
                    for (int i = 0; i < currentConfigParamParent.SUBCONTAINERS.Length; i++)
                    {
                        if (currentConfigParamParent.SUBCONTAINERS[i].PARAMETERVALUES.DEFINITIONREF.name.Equals(key, StringComparison.OrdinalIgnoreCase))
                        {
                            obj = currentConfigParamParent.SUBCONTAINERS[i];
                            isObjectFound = true;
                            break;
                        }
                    }
                    // if obj found, break out of all loops
                    if (isObjectFound) break;
                }
                // if obj found, break out of all loops
                if (isObjectFound) break;
            }

            return obj;
        }

        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUE RetrieveConfigParamObjectParent(string key)
        {

            bool isObjectFound = false;
            AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUE obj = null;

            var currentPackage = DockingManagerModelHelper.Configuration.ARPACKAGES.Where(x => String.Equals(x.SHORTNAME.ToString().ToLower(), DockingManagerModelHelper.ModuleName.ToLower())).FirstOrDefault();

            for (int j = 0; j < currentPackage.ELEMENTS.ECUCMODULECONFIGURATIONVALUES.CONTAINERS.SUBCONTAINERS.Length; j++)
            {
                var currentConfigParamGrandParent = currentPackage.ELEMENTS.ECUCMODULECONFIGURATIONVALUES.CONTAINERS.SUBCONTAINERS[j];

                //TODO: Need to refine below code to accept only filtered object.
                for (int k = 0; k < currentConfigParamGrandParent.SUBCONTAINERS.Length; k++)
                {
                    List<string> lstSupportedValues = new List<string>();
                    string strControlType = string.Empty;
                    var currentConfigParamParent = currentConfigParamGrandParent.SUBCONTAINERS[k];

                    // foreach (var currentConfigParamChild in currentConfigParamParent.SUBCONTAINERS)
                    for (int i = 0; i < currentConfigParamParent.SUBCONTAINERS.Length; i++)
                    {
                        if (currentConfigParamParent.SUBCONTAINERS[i].PARAMETERVALUES.DEFINITIONREF.name.Equals(key, StringComparison.OrdinalIgnoreCase))
                        {
                            obj = currentConfigParamParent;
                            isObjectFound = true;
                            break;
                        }
                    }
                    // if obj found, break out of all loops
                    if (isObjectFound) break;
                }
                // if obj found, break out of all loops
                if (isObjectFound) break;
            }

            return obj;
        }

        private void SaveBtn_Click(object sender, RoutedEventArgs e)
        {
            GetUpdatedValuesForConfigGeneration();
            DockingManagerModelHelper.UpdateARXML();
            MessageBox.Show("ARXML Successfully saved at following path : " + DockingManagerModelHelper.TargetOutputFolderPath);
        }

        private void LoadDefaultConfigBtn_Click(object sender, RoutedEventArgs e)
        {
            DockingManagerModelHelper.Configuration = DockingManagerModelHelper.LoadARXML(true);
            PopulateWorkspaceExplorer();
            CreateDynamicWPFGridForModule();

        }

        private void LoadDBCBtn_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            string stringFile = string.Empty;
            string FileExt = string.Empty;


            if (openFileDialog.ShowDialog() == true)
            {
                stringFile = File.ReadAllText(openFileDialog.FileName);
                FileExt = Path.GetExtension(openFileDialog.FileName);

            }

            if (FileExt.Equals(".dbc", StringComparison.OrdinalIgnoreCase))
            {
                string fpath = openFileDialog.FileName;
                fpath = fpath.Substring(0, fpath.Length - 4).Trim();

                if (fpath.LastIndexOf("(") > 0)
                {
                    fpath = fpath.Substring(0, fpath.LastIndexOf("(")).Trim();
                }
                fpath = fpath.ToLower().Replace(".", "").Replace("_", "") + ".dbc";
                allObjects = null;
                File.WriteAllText(DockingManagerModelHelper.TargetInputFolderPath + "\\" + Path.GetFileName(fpath), stringFile);
                DoCANManager(Path.GetFileName(fpath));
                allObjects = null;

                //CreateDynamicWPFGridForModule();
                DoCanIf();


                MessageBox.Show(openFileDialog.FileName + " Loaded Successfully.");
            }
            else
            {
                MessageBox.Show("please eneter valid .dbc file.");
            }

        }
    }
}