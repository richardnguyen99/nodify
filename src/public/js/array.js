/* eslint-disable no-param-reassign */
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
  arrayContainer.style.width = `${randomArray.length * (50 + 8)}px`;
  arrayNodeList.style.height = "50px";
  arrayNodeList.style.width = `${randomArray.length * (50 + 8)}px`;

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

/**
 * Elements swapping animation
 *
 * @param {HTMLElement} element1
 * @param {HTMLElement} element2
 * @param {HTMLElement} arrayContainer
 *
 * @returns {void}
 */
function swapElement(element1, element2, arrayContainer) {
  return new Promise((resolve) => {
    const tempClassList = element1.classList;
    const tempTransform = element1.style.transform;

    element1.classList = element2.classList;
    element1.style.transform = element2.style.transform;
    element2.classList = tempClassList;
    element2.style.transform = tempTransform;

    window.requestAnimationFrame(() => {
      setTimeout(() => {
        arrayContainer.insertBefore(element2, element1);
        resolve();
      }, 250);
    });
  });
}

/**
 *
 * @param {number} index1
 * @param {number} index2
 * @param {HTMLElement} arrayContainer
 */
function swapIndexElement(index1, index2, arrayContainer) {
  const element1 = arrayContainer.childNodes.item(index1);
  const element2 = arrayContainer.childNodes.item(index2);
  const element2Sibling = arrayContainer.childNodes.item(index2 + 1);

  return new Promise((resolve) => {
    const tempClassList = element1.classList;
    const tempTransform = element1.style.transform;

    element1.classList = element2.classList;
    element1.style.transform = element2.style.transform;
    element2.classList = tempClassList;
    element2.style.transform = tempTransform;

    window.requestAnimationFrame(() => {
      setTimeout(() => {
        arrayContainer.insertBefore(element2, element1);
        arrayContainer.insertBefore(element1, element2Sibling);
        resolve();
      }, 250);
    });
  });
}

// eslint-disable-next-line no-unused-vars
function bubbleSort() {
  const xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = async function () {
    // eslint-disable-next-line eqeqeq
    if (this.readyState == 4 && this.status == 200) {
      array = xhttp.response.sortedArray;
      animation = xhttp.response.animation;

      let arrayListItems = document.querySelectorAll(".array__list-node__item");
      const arrayContainer = document.querySelector(".array__container");

      for (let i = 0; i < animation.length; i += 1) {
        const [type, index1, index2] = animation[i];

        if (type === 0) {
          arrayListItems[index1].classList.add(
            "array__list-node__item--warning",
          );
          arrayListItems[index2].classList.add(
            "array__list-node__item--warning",
          );
        } else if (type === 1) {
          // eslint-disable-next-line no-await-in-loop
          await swapElement(
            arrayListItems[index1],
            arrayListItems[index2],
            arrayContainer.querySelector(".array__list-node"),
          );

          arrayListItems = document.querySelectorAll(".array__list-node__item");
        }

        // eslint-disable-next-line no-await-in-loop
        await new Promise((resolve) => {
          setTimeout(() => {
            resolve();
          }, 250);
        });

        arrayListItems[index1].classList.remove(
          "array__list-node__item--warning",
        );
        arrayListItems[index2].classList.remove(
          "array__list-node__item--warning",
        );
      }

      for (let i = 0; i < arrayListItems.length; i += 1) {
        setTimeout(() => {
          arrayListItems[i].classList.add("array__list-node__item--success");
        }, i * 100);
      }
    }
  };

  xhttp.responseType = "json";
  xhttp.open("POST", "/algorithm/sorting/bubble-sort");
  xhttp.setRequestHeader("Content-Type", "application/json;charset=utf-8");
  xhttp.send(JSON.stringify({ array }));
}

// eslint-disable-next-line no-unused-vars
function insertionSort() {
  const xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = async function () {
    // eslint-disable-next-line eqeqeq
    if (this.readyState == 4 && this.status == 200) {
      array = xhttp.response.sortedArray;
      animation = xhttp.response.animation;

      let arrayListItems = document.querySelectorAll(".array__list-node__item");
      const arrayContainer = document.querySelector(".array__container");

      for (let i = 0; i < animation.length; i += 1) {
        const [type, index1, index2] = animation[i];

        if (type === 0) {
          arrayListItems[index1].classList.add(
            "array__list-node__item--warning",
          );
          arrayListItems[index2].classList.add(
            "array__list-node__item--warning",
          );
        } else if (type === 1) {
          // eslint-disable-next-line no-await-in-loop
          await swapElement(
            arrayListItems[index2],
            arrayListItems[index1],
            arrayContainer.querySelector(".array__list-node"),
          );

          arrayListItems = document.querySelectorAll(".array__list-node__item");
        }

        // eslint-disable-next-line no-await-in-loop
        await new Promise((resolve) => {
          setTimeout(() => {
            resolve();
          }, 250);
        });

        arrayListItems[index1].classList.remove(
          "array__list-node__item--warning",
        );
        arrayListItems[index2].classList.remove(
          "array__list-node__item--warning",
        );
      }

      for (let i = 0; i < arrayListItems.length; i += 1) {
        setTimeout(() => {
          arrayListItems[i].classList.add("array__list-node__item--success");
        }, i * 100);
      }
    }
  };

  xhttp.responseType = "json";
  xhttp.open("POST", "/algorithm/sorting/insertion-sort");
  xhttp.setRequestHeader("Content-Type", "application/json;charset=utf-8");
  xhttp.send(JSON.stringify({ array }));
}

// eslint-disable-next-line no-unused-vars
function selectionSort() {
  const xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = async function () {
    // eslint-disable-next-line eqeqeq
    if (this.readyState == 4 && this.status == 200) {
      array = xhttp.response.sortedArray;
      animation = xhttp.response.animation;

      let arrayListItems = document.querySelectorAll(".array__list-node__item");
      const arrayContainer = document.querySelector(".array__container");

      for (let i = 0; i < animation.length; i += 1) {
        const [type, index1, index2] = animation[i];

        if (type === 0) {
          arrayListItems[index1].classList.add(
            "array__list-node__item--warning",
          );
          arrayListItems[index2].classList.add(
            "array__list-node__item--warning",
          );
        } else if (type === 1) {
          // eslint-disable-next-line no-await-in-loop
          await swapIndexElement(
            index1,
            index2,
            arrayContainer.querySelector(".array__list-node"),
          );

          arrayListItems = document.querySelectorAll(".array__list-node__item");
        }

        // eslint-disable-next-line no-await-in-loop
        await new Promise((resolve) => {
          setTimeout(() => {
            resolve();
          }, 250);
        });

        arrayListItems[index1].classList.remove(
          "array__list-node__item--warning",
        );
        arrayListItems[index2].classList.remove(
          "array__list-node__item--warning",
        );
      }

      for (let i = 0; i < arrayListItems.length; i += 1) {
        setTimeout(() => {
          arrayListItems[i].classList.add("array__list-node__item--success");
        }, i * 100);
      }
    }
  };

  xhttp.responseType = "json";
  xhttp.open("POST", "/algorithm/sorting/selection-sort");
  xhttp.setRequestHeader("Content-Type", "application/json;charset=utf-8");
  xhttp.send(JSON.stringify({ array }));
}
