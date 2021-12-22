using System.Collections.Generic;

namespace SharpBrain.Utils
{
    public static class ListExtensions
    {
        public static List<T> Slice<T>(this List<T> list, int start, int end)
        {
            if (start > end)
            {
                int temp = end;
                end = start;
                start = temp;
            }
            var cap = end - start;
            var res = new List<T>(cap);
            for (int i = 0; i <= cap; ++i)
            {
                res.Add(list[i + start]);
            }
            return res;
        }
    }
}
