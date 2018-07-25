using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithms
{
    public static class ProgramMgr
    {
        public static void run()
        {
            Menu m = new Menu();
            m.initialize();

            while (m.IsRunning)
            {
                m.options();
            }
        }
    }
}
