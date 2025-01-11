class Solution {
public:
    string intToRoman(int num) {
        // create a hash map to store symbol to value
        // Run a loop
        //  1. Each iteration take the <= num value from the hash map
        //     and divide it by num to get the number of instances
        //     required of that symbol
        //  2. Next get the remainder of num=num%symbol to and get num ready
        //     for next iteration.

        map<int, string> roman = {
          {1000, "M"},
          {900, "CM"},
          {500, "D"},
          {400, "CD"},
          {100, "C"},
          {90, "XC" },
          {50, "L"},
          {40, "XL"},
          {10, "X"},
          {9, "IX"},
          {5, "V"},
          {4, "IV"},
          {1, "I"},
        };

        string result;
        for (auto rit = roman.rbegin(); rit != roman.rend(); ++rit) {
            auto key = rit->first;
            auto val = rit->second;
            if (num == 0) break;
            int x = num/key; // x -> number of times val corresponding to the key should be in the result 
            while(x--) {
                result += val;
            }
            num %= key;
        }
        return result;
    }
};








                                                                                                                                        ███╗   ██╗███████╗ ██████╗ ██╗   ██╗██╗███╗   ███╗
                                                                                                                                        ████╗  ██║██╔════╝██╔═══██╗██║   ██║██║████╗ ████║
                                                                                                                                        ██╔██╗ ██║█████╗  ██║   ██║██║   ██║██║██╔████╔██║
                                                                                                                                        ██║╚██╗██║██╔══╝  ██║   ██║╚██╗ ██╔╝██║██║╚██╔╝██║
                                                                                                                                        ██║ ╚████║███████╗╚██████╔╝ ╚████╔╝ ██║██║ ╚═╝ ██║
                                                                                                                                        ╚═╝  ╚═══╝╚══════╝ ╚═════╝   ╚═══╝  ╚═╝╚═╝     ╚═╝

                                                                                                                                                         [ @holdmypotion ]



                                                                                                                                      �  Find file                                     f

                                                                                                                                        New file                                      n

                                                                                                                                        Recent files                                  r

                                                                                                                                        Find text                                     g

                                                                                                                                        Config                                        c

                                                                                                                                        Restore Session                               s

                                                                                                                                        Lazy Extras                                   x

                                                                                                                                      󰒲  Lazy                                          l

                                                                                                                                        Quit                                          q

                                                                                                                                           ⚡ Neovim loaded 5/49 plugins in 37.36ms
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
                                                                                                                                                                                                                                                                                                            20,140-138    All
                                                                                                                                                                                                                                                                                                                 [-] [Scratch]








                                                                                                                                        ███╗   ██╗███████╗ ██████╗ ██╗   ██╗██╗███╗   ███╗
                                                                                                                                        ████╗  ██║██╔════╝██╔═══██╗██║   ██║██║████╗ ████║
                                                                                                                                        ██╔██╗ ██║█████╗  ██║   ██║██║   ██║██║██╔████╔██║
                                                                                                                                        ██║╚██╗██║██╔══╝  ██║   ██║╚██╗ ██╔╝██║██║╚██╔╝██║
                                                                                                                                        ██║ ╚████║███████╗╚██████╔╝ ╚████╔╝ ██║██║ ╚═╝ ██║
                                                                                                                                        ╚═╝  ╚═══╝╚══════╝ ╚═════╝   ╚═══╝  ╚═╝╚═╝     ╚═╝

                                                                                                                                                         [ @holdmypotion ]



                                                                                                                                      �  Find file                                     f

                                                                                                                                        New file                                      n

                                                                                                                                        Recent files                                  r

                                                                                                                                        Find text                                     g

                                                                                                                                        Config                                        c

                                                                                                                                        Restore Session                               s

                                                                                                                                        Lazy Extras                                   x

                                                                                                                                      󰒲  Lazy                                          l

                                                                                                                                        Quit                                          q

                                                                                                                                           ⚡ Neovim loaded 5/49 plugins in 39.58ms
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
                                                                                                                                                                                                                                                                                                            20,140-138    All
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
 NORMAL   main    leetcode/int_to_roman.cpp                                                                                                                                                                                                                                                 :   7  65%  25:18   13:27
                                                                                                                                                         leetcode/int_to_roman.cpp
  24   class Solution {
  23   public:
  22   │   string intToRoman(int num) {
  21   │   │   // create a hash map to store symbol to value
  20   │   │   // Run a loop
  19   │   │   //  1. Each iteration take the <= num value from the hash map
  18   │   │   //     and divide it by num to get the number of instances
  17   │   │   //     required of that symbol
  16   │   │   //  2. Next get the remainder of num=num%symbol to and get num ready
  15   │   │   //     for next iteration.
  14   │   │
  13   │   │   map<int, string> roman = {
  12   │   │   │ {1000, "M"},
  11   │   │   │ {900, "CM"},
  10   │   │   │ {500, "D"},
   9   │   │   │ {400, "CD"},
   8   │   │   │ {100, "C"},
   7   │   │   │ {90, "XC" },
   6   │   │   │ {50, "L"},
   5   │   │   │ {40, "XL"},
   4   │   │   │ {10, "X"},
   3   │   │   │ {9, "IX"},
   2   │   │   │ {5, "V"},
   1   │   │   │ {4, "IV"},
  25   │   │   │ {1, "I"},
   1   │   │   };
   2   │   │
   3   │   │   string result;
   4   │   │
   5   │   │   int i = 0;
   6   │   │   wihle (true) {
   7   │   │   │ if (num == 0) break;
   8   │---│---│-│
   9   │   │   }
  10   │   │
  11   │   │   return result;
  12   │   }
  13   };
~
~
~
~
~
~
 NORMAL   main    leetcode/int_to_roman.cpp                                                                                                     :   7  65%  25:18   13:27
                                                                                                                                                                     [-] [Scratch]








                                                                  ███╗   ██╗███████╗ ██████╗ ██╗   ██╗██╗███╗   ███╗
                                                                  ████╗  ██║██╔════╝██╔═══██╗██║   ██║██║████╗ ████║
                                                                  ██╔██╗ ██║█████╗  ██║   ██║██║   ██║██║██╔████╔██║
                                                                  ██║╚██╗██║██╔══╝  ██║   ██║╚██╗ ██╔╝██║██║╚██╔╝██║
                                                                  ██║ ╚████║███████╗╚██████╔╝ ╚████╔╝ ██║██║ ╚═╝ ██║
                                                                  ╚═╝  ╚═══╝╚══════╝ ╚═════╝   ╚═══╝  ╚═╝╚═╝     ╚═╝

                                                                                   [ @holdmypotion ]



                                                                �  Find file                                     f

                                                                  New file                                      n

                                                                  Recent files                                  r

                                                                  Find text                                     g

                                                                  Config                                        c

                                                                  Restore Session                               s

                                                                  Lazy Extras                                   x

                                                                󰒲  Lazy                                          l

                                                                  Quit                                          q

                                                                     ⚡ Neovim loaded 5/49 plugins in 47.19ms
~
~
~
~
~
~
                                                                                                                                                                20,70-68      All
                                                                                                                                                         leetcode/int_to_roman.cpp
  27   class Solution {
  26   public:
  25   │   string intToRoman(int num) {
  24   │   │   // create a hash map to store symbol to value
  23   │   │   // Run a loop
  22   │   │   //  1. Each iteration take the <= num value from the hash map
  21   │   │   //     and divide it by num to get the number of instances
  20   │   │   //     required of that symbol
  19   │   │   //  2. Next get the remainder of num=num%symbol to and get num ready
  18   │   │   //     for next iteration.
  17   │   │
  16   │   │   map<int, string> roman = {
  15   │   │   │ {1000, "M"},
  14   │   │   │ {900, "CM"},
  13   │   │   │ {500, "D"},
  12   │   │   │ {400, "CD"},
  11   │   │   │ {100, "C"},
  10   │   │   │ {90, "XC" },
   9   │   │   │ {50, "L"},
   8   │   │   │ {40, "XL"},
   7   │   │   │ {10, "X"},
   6   │   │   │ {9, "IX"},
   5   │   │   │ {5, "V"},
   4   │   │   │ {4, "IV"},
   3   │   │   │ {1, "I"},
   2   │   │   };
   1   │   │
  28   │   │   string result;
   1   │   │
   2   │   │   for (auto& [key, val]: roman) {
   3   │   │   │ if (num == 0) break;
   4   │   │   │ int x = num/key; // x -> number of times val corresponding to the key should be in the result-
   5   │   │   │
   6   │   │   │ while(x--) {
   7   │   │   │ │ result += val;
   8   │   │   │ }
   9   │   │   │ num %= key;
  10   │   │   }
  11   │   │   return result;
  12   │   }
  13   };
~
~
~
 NORMAL   main    leetcode/int_to_roman.cpp                                                                                                     A   7  68%  28:22   13:41
