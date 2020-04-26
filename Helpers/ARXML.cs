using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConfigGenerator.Helper
{

    // NOTE: Generated code may require at least .NET Framework 4.5 or .NET Core/Standard 2.0.
    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    [System.Xml.Serialization.XmlRootAttribute(Namespace = "http://autosar.org/schema/r4.0", IsNullable = false)]
    public partial class AUTOSAROld
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUES
    {

        private string sHORTNAMEField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESDEFINITIONREF dEFINITIONREFField;

        private string iMPLEMENTATIONCONFIGVARIANTField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESMODULEDESCRIPTIONREF mODULEDESCRIPTIONREFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUE[] cONTAINERSField;

        private string uUIDField;

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
        [System.Xml.Serialization.XmlElementAttribute("IMPLEMENTATION-CONFIG-VARIANT")]
        public string IMPLEMENTATIONCONFIGVARIANT
        {
            get
            {
                return this.iMPLEMENTATIONCONFIGVARIANTField;
            }
            set
            {
                this.iMPLEMENTATIONCONFIGVARIANTField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("MODULE-DESCRIPTION-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESMODULEDESCRIPTIONREF MODULEDESCRIPTIONREF
        {
            get
            {
                return this.mODULEDESCRIPTIONREFField;
            }
            set
            {
                this.mODULEDESCRIPTIONREFField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayItemAttribute("ECUC-CONTAINER-VALUE", IsNullable = false)]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUE[] CONTAINERS
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

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string UUID
        {
            get
            {
                return this.uUIDField;
            }
            set
            {
                this.uUIDField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESMODULEDESCRIPTIONREF
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUE
    {

        private string sHORTNAMEField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEDEFINITIONREF dEFINITIONREFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEPARAMETERVALUES pARAMETERVALUESField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCREFERENCEVALUE[] rEFERENCEVALUESField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUE[] sUBCONTAINERSField;

        private string uUIDField;

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
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEDEFINITIONREF DEFINITIONREF
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
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEPARAMETERVALUES PARAMETERVALUES
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
        [System.Xml.Serialization.XmlArrayAttribute("REFERENCE-VALUES")]
        [System.Xml.Serialization.XmlArrayItemAttribute("ECUC-REFERENCE-VALUE", IsNullable = false)]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCREFERENCEVALUE[] REFERENCEVALUES
        {
            get
            {
                return this.rEFERENCEVALUESField;
            }
            set
            {
                this.rEFERENCEVALUESField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayAttribute("SUB-CONTAINERS")]
        [System.Xml.Serialization.XmlArrayItemAttribute("ECUC-CONTAINER-VALUE", IsNullable = false)]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUE[] SUBCONTAINERS
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

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string UUID
        {
            get
            {
                return this.uUIDField;
            }
            set
            {
                this.uUIDField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEDEFINITIONREF
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEPARAMETERVALUES
    {

        private object[] itemsField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("ECUC-NUMERICAL-PARAM-VALUE", typeof(AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEPARAMETERVALUESECUCNUMERICALPARAMVALUE))]
        [System.Xml.Serialization.XmlElementAttribute("ECUC-TEXTUAL-PARAM-VALUE", typeof(AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEPARAMETERVALUESECUCTEXTUALPARAMVALUE))]
        public object[] Items
        {
            get
            {
                return this.itemsField;
            }
            set
            {
                this.itemsField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEPARAMETERVALUESECUCNUMERICALPARAMVALUE
    {

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEPARAMETERVALUESECUCNUMERICALPARAMVALUEDEFINITIONREF dEFINITIONREFField;

        private float vALUEField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("DEFINITION-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEPARAMETERVALUESECUCNUMERICALPARAMVALUEDEFINITIONREF DEFINITIONREF
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
        public float VALUE
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
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEPARAMETERVALUESECUCNUMERICALPARAMVALUEDEFINITIONREF
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEPARAMETERVALUESECUCTEXTUALPARAMVALUE
    {

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEPARAMETERVALUESECUCTEXTUALPARAMVALUEDEFINITIONREF dEFINITIONREFField;

        private string vALUEField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("DEFINITION-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEPARAMETERVALUESECUCTEXTUALPARAMVALUEDEFINITIONREF DEFINITIONREF
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
        public string VALUE
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
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEPARAMETERVALUESECUCTEXTUALPARAMVALUEDEFINITIONREF
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCREFERENCEVALUE
    {

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCREFERENCEVALUEDEFINITIONREF dEFINITIONREFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCREFERENCEVALUEVALUEREF vALUEREFField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("DEFINITION-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCREFERENCEVALUEDEFINITIONREF DEFINITIONREF
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
        [System.Xml.Serialization.XmlElementAttribute("VALUE-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCREFERENCEVALUEVALUEREF VALUEREF
        {
            get
            {
                return this.vALUEREFField;
            }
            set
            {
                this.vALUEREFField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCREFERENCEVALUEDEFINITIONREF
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCREFERENCEVALUEVALUEREF
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUE
    {

        private string sHORTNAMEField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEDEFINITIONREF dEFINITIONREFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUES pARAMETERVALUESField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUE[] rEFERENCEVALUESField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUE[] sUBCONTAINERSField;

        private string uUIDField;

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
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEDEFINITIONREF DEFINITIONREF
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
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUES PARAMETERVALUES
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
        [System.Xml.Serialization.XmlArrayAttribute("REFERENCE-VALUES")]
        [System.Xml.Serialization.XmlArrayItemAttribute("ECUC-REFERENCE-VALUE", IsNullable = false)]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUE[] REFERENCEVALUES
        {
            get
            {
                return this.rEFERENCEVALUESField;
            }
            set
            {
                this.rEFERENCEVALUESField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlArrayAttribute("SUB-CONTAINERS")]
        [System.Xml.Serialization.XmlArrayItemAttribute("ECUC-CONTAINER-VALUE", IsNullable = false)]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUE[] SUBCONTAINERS
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

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string UUID
        {
            get
            {
                return this.uUIDField;
            }
            set
            {
                this.uUIDField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEDEFINITIONREF
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUES
    {

        private object[] itemsField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("ECUC-NUMERICAL-PARAM-VALUE", typeof(AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESECUCNUMERICALPARAMVALUE))]
        [System.Xml.Serialization.XmlElementAttribute("ECUC-TEXTUAL-PARAM-VALUE", typeof(AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESECUCTEXTUALPARAMVALUE))]
        public object[] Items
        {
            get
            {
                return this.itemsField;
            }
            set
            {
                this.itemsField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESECUCNUMERICALPARAMVALUE
    {

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESECUCNUMERICALPARAMVALUEDEFINITIONREF dEFINITIONREFField;

        private double vALUEField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("DEFINITION-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESECUCNUMERICALPARAMVALUEDEFINITIONREF DEFINITIONREF
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
        public double VALUE
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
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESECUCNUMERICALPARAMVALUEDEFINITIONREF
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESECUCTEXTUALPARAMVALUE
    {

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESECUCTEXTUALPARAMVALUEDEFINITIONREF dEFINITIONREFField;

        private string vALUEField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("DEFINITION-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESECUCTEXTUALPARAMVALUEDEFINITIONREF DEFINITIONREF
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
        public string VALUE
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
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEPARAMETERVALUESECUCTEXTUALPARAMVALUEDEFINITIONREF
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUE
    {

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUEDEFINITIONREF dEFINITIONREFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUEVALUEREF vALUEREFField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("DEFINITION-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUEDEFINITIONREF DEFINITIONREF
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
        [System.Xml.Serialization.XmlElementAttribute("VALUE-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUEVALUEREF VALUEREF
        {
            get
            {
                return this.vALUEREFField;
            }
            set
            {
                this.vALUEREFField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUEDEFINITIONREF
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUEVALUEREF
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUE
    {

        private string sHORTNAMEField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEDEFINITIONREF dEFINITIONREFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUE[] rEFERENCEVALUESField;

        private string uUIDField;

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
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEDEFINITIONREF DEFINITIONREF
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
        [System.Xml.Serialization.XmlArrayAttribute("REFERENCE-VALUES")]
        [System.Xml.Serialization.XmlArrayItemAttribute("ECUC-REFERENCE-VALUE", IsNullable = false)]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUE[] REFERENCEVALUES
        {
            get
            {
                return this.rEFERENCEVALUESField;
            }
            set
            {
                this.rEFERENCEVALUESField = value;
            }
        }

        /// <remarks/>
        [System.Xml.Serialization.XmlAttributeAttribute()]
        public string UUID
        {
            get
            {
                return this.uUIDField;
            }
            set
            {
                this.uUIDField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEDEFINITIONREF
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUE
    {

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUEDEFINITIONREF dEFINITIONREFField;

        private AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUEVALUEREF vALUEREFField;

        /// <remarks/>
        [System.Xml.Serialization.XmlElementAttribute("DEFINITION-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUEDEFINITIONREF DEFINITIONREF
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
        [System.Xml.Serialization.XmlElementAttribute("VALUE-REF")]
        public AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUEVALUEREF VALUEREF
        {
            get
            {
                return this.vALUEREFField;
            }
            set
            {
                this.vALUEREFField = value;
            }
        }
    }

    /// <remarks/>
    [System.SerializableAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUEDEFINITIONREF
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
    [System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true, Namespace = "http://autosar.org/schema/r4.0")]
    public partial class AUTOSARARPACKAGEELEMENTSECUCMODULECONFIGURATIONVALUESECUCCONTAINERVALUEECUCCONTAINERVALUEECUCCONTAINERVALUEECUCREFERENCEVALUEVALUEREF
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


}
