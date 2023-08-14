using System;
using System.Collections.Generic;

public class Solution {
        public int solution(int n, int[] lost, int[] reserve)
        {
            List<int> losts = new List<int>();
            losts.AddRange(lost);
            List<int> reserves = new List<int>();
            reserves.AddRange(reserve);
            losts.Sort();
            reserves.Sort();

            int count = n - lost.Length;
            foreach(int ls in lost)
            {
                if(reserves.Contains(ls))
                {
                    losts.Remove(ls);
                    reserves.Remove(ls);
                    count++;
                }    
            }

            int num = losts[0];
            while (losts.Count > 0 && reserves.Count > 0)
            {
                if (num - 1 == reserves[0] || num + 1 == reserves[0] || num == reserves[0])
                {
                    losts.Remove(num);
                    if (losts.Count > 0)
                        num = losts[0];
                    reserves.Remove(reserves[0]);
                    count++;
                }
                else if (num < reserves[0])
                {
                    losts.Remove(num);
                    if (losts.Count > 0)
                        num = losts[0];
                }
                else
                {
                    reserves.Remove(reserves[0]);
                }
            }
            return count;
        }
}