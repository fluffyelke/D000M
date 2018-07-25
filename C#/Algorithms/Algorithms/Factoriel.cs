using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithms
{
    public static class Factoriel
    {

        /**
         *   User menu
         *   1 - Compute N!
         *   2 - Compute how many digits has in N!
         */
        public static void factorielMenu()
        {
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine("########################################");
            Console.WriteLine("#        ИЗБЕРЕТЕ НУЖНАТА ОПЦИЯ        #");
            Console.WriteLine("#                                      #");
            Console.WriteLine("#  (1)        ПРЕСМЕТНЕТЕ N!           #");
            Console.WriteLine("#  (2)    БРОЯ НА ЦИФРИТЕ НА N!        #");
            Console.WriteLine("#                                      #");
            Console.WriteLine("#                                      #");
            Console.WriteLine("#                                      #");
            Console.WriteLine("#   ИЛИ ЧИСЛО РАЗЛИЧНО ОТ ИЗБРОЕНИТЕ   #");
            Console.WriteLine("#  ЗА ДА СЕ ВЪРНЕТЕ В ПРЕДИШНОТО МЕНЮ  #");
            Console.WriteLine("########################################");

            int option = Int32.Parse(Console.ReadLine());

            Console.WriteLine();
            Console.WriteLine();

            switch (option)
            {
                case 1:
                    printFactoriel();
                    break;
                case 2:
                    printDigitsOfNFactoriel();
                    break;
                default:
                    break;
            }
        }

        /**
         * Method which print the result of N!.
         */
        private static void printFactoriel()
        {
            Console.Write("Въведете числото за N! От 1 До 27: ");
            int number = Int32.Parse(Console.ReadLine());
            Console.WriteLine("Резултат: ");
            Console.WriteLine(factoriel(number));
            Console.WriteLine();
            Console.WriteLine();
        }

        /**
         * Recursive Method which compute N!.
         */ 
        private static decimal factoriel(decimal n)
        {
            if(n < 2)
            {
                return 1;
            }
            return n * factoriel(n - 1);
        }

        /**
         * Method which count how many digits has in N!.
         * 
         */ 
        private static void printDigitsOfNFactoriel()
        {
            Console.Write("Въведете число за N!: ");
            int number = Int32.Parse(Console.ReadLine());
            double digits = 1;

            for(int i = 1; i <= number; i++)
            {
                digits += Math.Log10(i);
            }
            Console.WriteLine("Броя на цифрите на N! e: {0}", (int)digits);
            Console.WriteLine();
            Console.WriteLine();
        }
    }
}
