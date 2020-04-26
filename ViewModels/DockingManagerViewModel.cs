using ConfigGenerator.Models;
using System.Collections.Generic;

namespace ConfigGenerator.ViewModels
{
    class DockingManagerViewModel
    {
        private List<DockingManagerModel> canDriverSupportedBitRates;
        public List<DockingManagerModel> CanDriverSupportedBitRates
        {
            get
            {
                return canDriverSupportedBitRates;
            }
            set
            {
                canDriverSupportedBitRates = value;
            }
        }
        public DockingManagerViewModel(List<string> strSupportedValues)
        {
            CanDriverSupportedBitRates = new List<DockingManagerModel>();
            foreach (string str in strSupportedValues)
            {
                CanDriverSupportedBitRates.Add(new DockingManagerModel()
                {
                    Name = str,
                    Value = str
                });
            }
        }
    }
}
