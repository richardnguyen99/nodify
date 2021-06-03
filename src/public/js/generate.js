/* eslint-disable no-unused-vars */
let array;

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
  arrayContainer.style.width = `${array.length * 50}px`;
  arrayNodeList.style.height = "50px";
  arrayNodeList.style.width = `${array.length * 50}px`;

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
  xhttp.send(JSON.stringify({ arrayRange: arrayRange.value }));
}
