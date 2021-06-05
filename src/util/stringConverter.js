/**
 * String converters
 *
 * @author Richard Nguyen <richard.ng0616@gmai.com>
 */

/**
 * Convert hyphen case to title case using Regex
 *
 * @example hyphenToTitle("first-name") // -> "First Name"
 *
 * @param {string} str
 * @returns {string}
 */
function hyphenToTitle(str) {
  return (
    str
      // Search for every dash and the following letters,
      // capitalize the first letter and add a blank space
      // before it.
      .replace(/-([a-zA-Z0-9])/g, (matchStr) => ` ${matchStr[1].toUpperCase()}`)
      // Go to the first letter of the previous
      // result and capitalize it since camel
      // case's first letter is lower case
      .replace(/^./, (matchStr) => matchStr.toUpperCase())
  );
}

module.exports = {
  hyphenToTitle,
};