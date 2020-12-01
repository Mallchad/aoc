#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
/*
 *
 * --- Day 1: Report Repair ---
 * Before you leave, the Elves in accounting just need you to fix your expense report (your puzzle input); apparently, something isn't quite adding up.
 *
 * Specifically, they need you to find the two entries that sum to 2020 and then multiply those two numbers together.
 *
 * For example, suppose your expense report contained the following:
 *
 * 1721
 * 979
 * 366
 * 299
 * 675
 * 1456
 *
 * In this list, the two entries that sum to 2020 are 1721 and 299. Multiplying them together produces 1721 * 299 = 514579, so the correct answer is 514579.
 *
 * Of course, your expense report is much larger. Find the two entries that sum to 2020; what do you get if you multiply them together?
 * --- Part Two ---
 * Using the above example again, the three entries that sum to 2020 are 979, 366, and
 *  675. Multiplying them together produces the answer, 241861950.

In your expense report, what is the product of the three entries that sum to 2020?
*/
#define DEBUG
void debug_message(std::string message)
{
#ifdef DEBUG
  std::cout << "advent_of_code DEBUG:" << message << "\n";
#endif
}

int day_1(bool use_stdin = false)
{
  int answer = 0;
  std::ifstream test_input("day1-input");
  std::vector<int> test_input_formatted(100);
  for (; !test_input.eof() ;)
    {
      static int tmp;
      test_input >> tmp;
      test_input_formatted.push_back(tmp);
      debug_message(std::to_string(tmp));
    }
  test_input_formatted.shrink_to_fit();
  for (const int& interogated : test_input_formatted)
    {
      for (const int& interogator_1 : test_input_formatted)
        {
          for (const int& interogator_2 : test_input_formatted)
            {
              int result = interogated + interogator_1 + interogator_2;
              debug_message(std::to_string(result));
              // debug_message("" + std::to_string(result == 2020));
              if (result == 2020)
                  {
                    answer = interogated * interogator_1 * interogator_2;
                    debug_message(std::to_string(answer));
                    std::cout << answer << "\n";
                    test_input.close();
                    return EXIT_SUCCESS;
                  }
            }
        }
    }
}

int main(int argc, char** argv)
{
  std::vector<int> puzzle_progress =
    {
      day_1(),
    };


  return EXIT_SUCCESS;
}
