#include "funkcijos.h"

/**
 * @brief Checks whether a string consists entirely of digit characters.
 *
 * Iterates over every character in `input` and returns false as soon as
 * a non-digit character is found. An empty string returns true (no
 * non-digits were found), so the caller should guard against empty input
 * separately if needed.
 *
 * This is used throughout the project to validate numeric user input
 * before calling `stoi()`, preventing crashes from letters or symbols.
 *
 * Example:
 * @code
 *   ar_valid("42")  // true
 *   ar_valid("4a")  // false
 *   ar_valid("")    // true  ← caller must check for empty separately
 * @endcode
 *
 * @param input The string to validate.
 * @return true  if every character is a digit (0–9).
 * @return false if any character is not a digit.
 */
bool ar_valid(const string& input) {
    for (const char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}