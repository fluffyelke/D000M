using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithms
{
    public class Menu
    {
        private bool isRunning = false;

        //Properties
        public bool IsRunning
        {
            get
            {
                return this.isRunning;
            }
            set
            {
                this.isRunning = value;
            }
        }

        public void initialize()
        {
            isRunning = true;
        }

        public void options()
        {
            Console.WriteLine("########################################");
            Console.WriteLine("#        ИЗБЕРЕТЕ НУЖНАТА ОПЦИЯ        #");
            Console.WriteLine("#                                      #");
            Console.WriteLine("#  (1)    ОПЕРАЦИИ С  ФАКТОРИЕЛ        #");
            Console.WriteLine("#                                      #");
            Console.WriteLine("#                                      #");
            Console.WriteLine("#                                      #");
            Console.WriteLine("#                                      #");
            Console.WriteLine("#                                      #");
            Console.WriteLine("#  (0)            ИЗХОД                #");
            Console.WriteLine("########################################");

            int option = Int32.Parse(Console.ReadLine());
            switch(option)
            {
                case 1:
                    Factoriel.factorielMenu();
                    break;

                case 0:
                    isRunning = false;
                    break;
                default: break;
            }
        }
    }
}
