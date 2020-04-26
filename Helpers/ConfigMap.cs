using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConfigGenerator.Helpers
{


    // NOTE: Generated code may require at least .NET Framework 4.5 or .NET Core/Standard 2.0.
    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
    public partial class AUTOSAR
    {

        private AUTOSARARPACKAGE[] aRPACKAGESField;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayAttribute("AR-PACKAGES")]
        [System.Xml.Serialization.XmlArrayItemAttribute("AR-PACKAGE", IsNullable = false)]
        public AUTOSARARPACKAGE[] ARPACKAGES
        {
            get
            {
                return this.aRPACKAGESField;
            }
            set
            {
                this.aRPACKAGESField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGE
    {

        private string sHORTNAMEField;

        private AUTOSARARPACKAGEELEMENTS eLEMENTSField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("SHORT-NAME")]
        public string SHORTNAME
        {
            get
            {
                return this.sHORTNAMEField;
            }
            set
            {
                this.sHORTNAMEField = value;
            }
        }

        /// <remarks/>
        public AUTOSARARPACKAGEELEMENTS ELEMENTS
        {
            get
            {
                return this.eLEMENTSField;
            }
            set
            {
                this.eLEMENTSField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTS
    {

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUES eCUCMODULECONFIGURATIONVALUESField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("ECUC-MODULE-CONFIGURATION-VALUES")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUES ECUCMODULECONFIGURATIONVALUES
        {
            get
            {
                return this.eCUCMODULECONFIGURATIONVALUESField;
            }
            set
            {
                this.eCUCMODULECONFIGURATIONVALUESField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUES
    {

        private string sHORTNAMEField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESDEFINITIONREF dEFINITIONREFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERS cONTAINERSField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("SHORT-NAME")]
        public string SHORTNAME
        {
            get
            {
                return this.sHORTNAMEField;
            }
            set
            {
                this.sHORTNAMEField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("DEFINITION-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESDEFINITIONREF DEFINITIONREF
        {
            get
            {
                return this.dEFINITIONREFField;
            }
            set
            {
                this.dEFINITIONREFField = value;
            }
        }

        /// <remarks/>
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERS CONTAINERS
        {
            get
            {
                return this.cONTAINERSField;
            }
            set
            {
                this.cONTAINERSField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESDEFINITIONREF
    {

        private string dESTField;

        private string valueField;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string DEST
        {
            get
            {
                return this.dESTField;
            }
            set
            {
                this.dESTField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlTextAttribute()]
        public string Value
        {
            get
            {
                return this.valueField;
            }
            set
            {
                this.valueField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERS
    {

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUE[] sUBCONTAINERSField;

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayAttribute("SUB-CONTAINERS")]
        [System.Xml.Serialization.XmlArrayItemAttribute("ECUC-CONTAINER-VALUE", IsNullable = false)]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUE[] SUBCONTAINERS
        {
            get
            {
                return this.sUBCONTAINERSField;
            }
            set
            {
                this.sUBCONTAINERSField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUE
    {

        private string sHORTNAMEField;

        private string bRIEFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEDEFINITIONREF dEFINITIONREFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUE[] sUBCONTAINERSField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("SHORT-NAME")]
        public string SHORTNAME
        {
            get
            {
                return this.sHORTNAMEField;
            }
            set
            {
                this.sHORTNAMEField = value;
            }
        }

        /// <remarks/>
        public string BRIEF
        {
            get
            {
                return this.bRIEFField;
            }
            set
            {
                this.bRIEFField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("DEFINITION-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEDEFINITIONREF DEFINITIONREF
        {
            get
            {
                return this.dEFINITIONREFField;
            }
            set
            {
                this.dEFINITIONREFField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayAttribute("SUB-CONTAINERS")]
        [System.Xml.Serialization.XmlArrayItemAttribute("ECUC-CONTAINER-VALUE", IsNullable = false)]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUE[] SUBCONTAINERS
        {
            get
            {
                return this.sUBCONTAINERSField;
            }
            set
            {
                this.sUBCONTAINERSField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEDEFINITIONREF
    {

        private string dESTField;

        private string valueField;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string DEST
        {
            get
            {
                return this.dESTField;
            }
            set
            {
                this.dESTField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlTextAttribute()]
        public string Value
        {
            get
            {
                return this.valueField;
            }
            set
            {
                this.valueField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUE
    {

        private string sHORTNAMEField;

        private string bRIEFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEDEFINITIONREF dEFINITIONREFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUES pARAMETERVALUESField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUE[] sUBCONTAINERSField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("SHORT-NAME")]
        public string SHORTNAME
        {
            get
            {
                return this.sHORTNAMEField;
            }
            set
            {
                this.sHORTNAMEField = value;
            }
        }

        /// <remarks/>
        public string BRIEF
        {
            get
            {
                return this.bRIEFField;
            }
            set
            {
                this.bRIEFField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("DEFINITION-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEDEFINITIONREF DEFINITIONREF
        {
            get
            {
                return this.dEFINITIONREFField;
            }
            set
            {
                this.dEFINITIONREFField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("PARAMETER-VALUES")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUES PARAMETERVALUES
        {
            get
            {
                return this.pARAMETERVALUESField;
            }
            set
            {
                this.pARAMETERVALUESField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayAttribute("SUB-CONTAINERS")]
        [System.Xml.Serialization.XmlArrayItemAttribute("ECUC-CONTAINER-VALUE", IsNullable = false)]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUE[] SUBCONTAINERS
        {
            get
            {
                return this.sUBCONTAINERSField;
            }
            set
            {
                this.sUBCONTAINERSField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEDEFINITIONREF
    {

        private string dESTField;

        private string valueField;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string DEST
        {
            get
            {
                return this.dESTField;
            }
            set
            {
                this.dESTField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlTextAttribute()]
        public string Value
        {
            get
            {
                return this.valueField;
            }
            set
            {
                this.valueField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUES
    {

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESDEFINITIONREF dEFINITIONREFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESVALUE vALUEField;

        private string[] sUPPORTEDVALUESField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("DEFINITION-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESDEFINITIONREF DEFINITIONREF
        {
            get
            {
                return this.dEFINITIONREFField;
            }
            set
            {
                this.dEFINITIONREFField = value;
            }
        }

        /// <remarks/>
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESVALUE VALUE
        {
            get
            {
                return this.vALUEField;
            }
            set
            {
                this.vALUEField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayAttribute("SUPPORTED-VALUES")]
        [System.Xml.Serialization.XmlArrayItemAttribute("SUPPORTED-VALUE", IsNullable = false)]
        public string[] SUPPORTEDVALUES
        {
            get
            {
                return this.sUPPORTEDVALUESField;
            }
            set
            {
                this.sUPPORTEDVALUESField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESDEFINITIONREF
    {

        private string dESTField;

        private string nameField;

        private string valueField;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string DEST
        {
            get
            {
                return this.dESTField;
            }
            set
            {
                this.dESTField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string name
        {
            get
            {
                return this.nameField;
            }
            set
            {
                this.nameField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlTextAttribute()]
        public string Value
        {
            get
            {
                return this.valueField;
            }
            set
            {
                this.valueField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESVALUE
    {

        private string supplementaryValueField;

        private string unitField;

        private string valueField;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string SupplementaryValue
        {
            get
            {
                return this.supplementaryValueField;
            }
            set
            {
                this.supplementaryValueField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string Unit
        {
            get
            {
                return this.unitField;
            }
            set
            {
                this.unitField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlTextAttribute()]
        public string Value
        {
            get
            {
                return this.valueField;
            }
            set
            {
                this.valueField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUE
    {

        private string sHORTNAMEField;

        private string bRIEFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEDEFINITIONREF dEFINITIONREFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUES pARAMETERVALUESField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("SHORT-NAME")]
        public string SHORTNAME
        {
            get
            {
                return this.sHORTNAMEField;
            }
            set
            {
                this.sHORTNAMEField = value;
            }
        }

        /// <remarks/>
        public string BRIEF
        {
            get
            {
                return this.bRIEFField;
            }
            set
            {
                this.bRIEFField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("DEFINITION-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEDEFINITIONREF DEFINITIONREF
        {
            get
            {
                return this.dEFINITIONREFField;
            }
            set
            {
                this.dEFINITIONREFField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("PARAMETER-VALUES")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUES PARAMETERVALUES
        {
            get
            {
                return this.pARAMETERVALUESField;
            }
            set
            {
                this.pARAMETERVALUESField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEDEFINITIONREF
    {

        private string dESTField;

        private string valueField;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string DEST
        {
            get
            {
                return this.dESTField;
            }
            set
            {
                this.dESTField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlTextAttribute()]
        public string Value
        {
            get
            {
                return this.valueField;
            }
            set
            {
                this.valueField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUES
    {

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESDEFINITIONREF dEFINITIONREFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESVALUE vALUEField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESSUPPORTEDVALUES sUPPORTEDVALUESField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("DEFINITION-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESDEFINITIONREF DEFINITIONREF
        {
            get
            {
                return this.dEFINITIONREFField;
            }
            set
            {
                this.dEFINITIONREFField = value;
            }
        }

        /// <remarks/>
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESVALUE VALUE
        {
            get
            {
                return this.vALUEField;
            }
            set
            {
                this.vALUEField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("SUPPORTED-VALUES")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESSUPPORTEDVALUES SUPPORTEDVALUES
        {
            get
            {
                return this.sUPPORTEDVALUESField;
            }
            set
            {
                this.sUPPORTEDVALUESField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESDEFINITIONREF
    {

        private string dESTField;

        private string nameField;

        private string valueField;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string DEST
        {
            get
            {
                return this.dESTField;
            }
            set
            {
                this.dESTField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string name
        {
            get
            {
                return this.nameField;
            }
            set
            {
                this.nameField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlTextAttribute()]
        public string Value
        {
            get
            {
                return this.valueField;
            }
            set
            {
                this.valueField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESVALUE
    {

        private string supplementaryValueField;

        private string unitField;

        private string valueField;

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string SupplementaryValue
        {
            get
            {
                return this.supplementaryValueField;
            }
            set
            {
                this.supplementaryValueField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string Unit
        {
            get
            {
                return this.unitField;
            }
            set
            {
                this.unitField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlTextAttribute()]
        public string Value
        {
            get
            {
                return this.valueField;
            }
            set
            {
                this.valueField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESCONTAINERSECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESSUPPORTEDVALUES
    {

        private string[] sUPPORTEDVALUEField;

        private byte minValueField;

        private string maxValueField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("SUPPORTED-VALUE")]
        public string[] SUPPORTEDVALUE
        {
            get
            {
                return this.sUPPORTEDVALUEField;
            }
            set
            {
                this.sUPPORTEDVALUEField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public byte MinValue
        {
            get
            {
                return this.minValueField;
            }
            set
            {
                this.minValueField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string MaxValue
        {
            get
            {
                return this.maxValueField;
            }
            set
            {
                this.maxValueField = value;
            }
        }
    }


}
