#include <iostream>
#include <string>
#include <fstream>
#include <sys/wait.h>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <sstream>
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
// #define DEBUG
template<typename t_streamable>
void debug_message(t_streamable message)
{
#ifdef DEBUG
    std::cout << "advent_of_code DEBUG:" << message << "\n";
#endif
}
/*
 *
 * Their password database seems to be a little corrupted: some of the
 * passwords wouldn't have been allowed by the Official Toboggan Corporate
 * Policy that was in effect when they were chosen.
 *
 * To try to debug the problem, they have created a list (your puzzle input)
 * of passwords (according to the corrupted database) and the corporate policy
 * when that password was set.
 *
 * For example, suppose you have the following list:
 *
 * 1-3 a: abcde
 * 1-3 b: cdefg
 * 2-9 c: ccccccccc
 *
 * Each line gives the password policy and then the password.
 * The password policy indicates the lowest and highest number of times a given
 * letter must appear for the password to be valid. For example, 1-3 a means
 *  that the password must contain a at least 1 time and at most 3 times.
 *
 * In the above example, 2 passwords are valid. The middle password, cdefg,
 * is not; it contains no instances of b, but needs at least 1. The first
 * and third passwords are valid: they contain one a or nine c, both within the limits of their respective policies.
 *
 * How many passwords are valid according to their policies?
 */

int day2()
{
    std::ifstream test_input_file("day2-input");

    std::stringstream test_input;
    test_input << test_input_file.rdbuf();
    test_input_file.close();
    unsigned correct_passwords = 0;
    while (!test_input.eof())
    {
      int character_position1 = 0;
      int character_position2 = 0;
      char character_restricted = 0;
      unsigned character_restricted_count = 0;
      std::string password;
      test_input >> character_position1;
      test_input.get(); // Destroy leading negative sign '-'
      test_input >> character_position2
                 >> character_restricted;
      test_input.get(); // Destroy leading colon ':'
      test_input >> password;
      // debug_message(character_position1);
      // debug_message(character_position2);
      // debug_message(character_restricted);
      // debug_message(password);
      bool character_check1 = password[character_position1-1] == character_restricted;
      bool character_check2 = password[character_position2-1] == character_restricted;
      if (character_check1 ^ character_check2)
      {
          ++correct_passwords;
          debug_message(correct_passwords);
          // debug_message(password);
          debug_message("true");
      }
      else
        {
            // debug_message(password);
            debug_message("false");
            // debug_message(correct_passwords);
        }
    }

    std::cout << "Correct Password Count:" << correct_passwords
              << std::endl        ;
    return EXIT_SUCCESS;
     }
        int main(int argc, char** argv)
    {
        // iostream performance hack
        std::cin.tie(nullptr);
        std::ios_base::sync_with_stdio(false);

        std::vector<int> puzzle_progress =
            {
                // day_1(),
                day2()
            };


        return EXIT_SUCCESS;
    }
