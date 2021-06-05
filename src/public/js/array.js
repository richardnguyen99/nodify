/**
 * Functions and settings for sorting and array-based
 * data structures and algorithms
 *
 * @author Richard Nguyen <richard.ng0616@gmail.com>
 */

let array;
// eslint-disable-next-line no-unused-vars
let animation = [];

/**
 * Generate an array of node elements based on the given array
 *
 * This function is to generate components, not to generate
 * the actual random array
 *
 * @param {Array<Number>} randomArray
 * @returns {void}
 */
function generateNodeArray(randomArray) {
  const arrayNodeList = document.createElement("ol");
  const arrayContainer = document.querySelector(".array__container");
  arrayNodeList.classList.add("array__list-node");

  arrayContainer.style.height = "50px";
  arrayContainer.style.width = `${randomArray.length * 50}px`;
  arrayNodeList.style.height = "50px";
  arrayNodeList.style.width = `${randomArray.length * 50}px`;

  arrayContainer.appendChild(arrayNodeList);

  for (let i = 0; i < randomArray.length; i += 1) {
    const listElement = document.createElement("li");
    listElement.classList.add("array__list-node__item");
    listElement.style.width = "50px";
    listElement.style.height = "50px";
    listElement.style.padding = "12.5px 0";
    listElement.style.transform = `translate(${i * 50 + 8 * i}px)`;

    listElement.appendChild(document.createTextNode(randomArray[i]));
    arrayContainer.querySelector("ol").appendChild(listElement);
  }
}

/**
 * Generate an array of random integers based on
 * the response from Express API /generate/array
 */
// eslint-disable-next-line no-unused-vars
function generateArray() {
  const arrayRange = document.querySelector("#arrayRange");
  const arrayContainer = document.querySelector(".array__container");

  const xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function () {
    // eslint-disable-next-line eqeqeq
    if (this.readyState == 4 && this.status == 200) {
      array = xhttp.response.array;

      arrayContainer.innerHTML = "";
      if (document.querySelector("#arrayBar").checked) {
        // generateBarArray(array);
      } else {
        generateNodeArray(array);
      }
    }
  };

  xhttp.responseType = "json";
  xhttp.open("POST", "/generate/array");
  xhttp.setRequestHeader("Content-Type", "application/json;charset=UTF-8");

  if (arrayRange.value <= 15 && arrayRange.value > 0) {
    xhttp.send(JSON.stringify({ arrayRange: arrayRange.value }));
  } else {
    xhttp.send(JSON.stringify({ arrayRange: 15 }));
  }
}

// eslint-disable-next-line no-unused-vars
function bubbleSort() {
  const xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = async function () {
    // eslint-disable-next-line eqeqeq
    if (this.readyState == 4 && this.status == 200) {
      array = xhttp.response.sortedArray;
      animation = [];
    }
  };

  xhttp.responseType = "json";
  xhttp.open("POST", "/algorithm/sorting/bubble-sort");
  xhttp.setRequestHeader("Content-Type", "application/json;charset=utf-8");
  xhttp.send(JSON.stringify({ array }));
}
