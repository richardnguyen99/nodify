let array;

function sort() {
  const arrayLayout = document.querySelector("#arrayLayout");
  const arrayContainer = document.querySelector(".array-container");
  const xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      array = xhttp.response.sortedArray;

      if (arrayLayout.value === "array") {
        arrayContainer.innerHTML = "";
        arrayContainer.appendChild(document.createElement("ol"));

        for (let i = 0; i < array.length; i++) {
          const listElement = document.createElement("li");
          listElement.setAttribute("id", array[i]);

          const spanElement = document.createElement("span");
          spanElement.appendChild(document.createTextNode(array[i]));
          listElement.appendChild(spanElement);
          arrayContainer.querySelector("ol").appendChild(listElement);
        }
      }
    }
  };

  xhttp.responseType = "json";
  xhttp.open("POST", "/algorithm/sorting");
  xhttp.setRequestHeader("Content-Type", "application/json;charset=UTF-8");

  if (!array) {
    const alertComponent = document.createElement("div");
    alertComponent.setAttribute("role", "alert");
    alertComponent.classList.add("alert", "alert-danger", "alert-dismissible", "fade", "show");

    const alertDismiss = document.createElement("button");
    alertDismiss.setAttribute("type", "button");
    alertDismiss.setAttribute("data-bs-dismiss", "alert");
    alertDismiss.setAttribute("aria-label", "Close");
    alertDismiss.classList.add("btn-close");

    alertComponent.appendChild(document.createTextNode("You need to generate an array first!"));
    alertComponent.appendChild(alertDismiss);
    arrayContainer.appendChild(alertComponent);

    setTimeout(function () {
      document.querySelector(".alert").classList.remove("show");

      setTimeout(function () {
        arrayContainer.removeChild(document.querySelector(".alert"));
      }, 1000);
    }, 3000);
  } else {
    xhttp.send(JSON.stringify({"array": array}));
  }
}

function generate() {
  const arrayRange = document.querySelector("#arrayRange");
  const arrayLayout = document.querySelector("#arrayLayout");
  const arrayContainer = document.querySelector(".array-container");

  const xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      array = xhttp.response.array;

      if (document.querySelector(".alert")) {
        arrayContainer.removeChild(document.querySelector(".alert"));
      }

      if (arrayLayout.value === "array") {
        arrayContainer.innerHTML = "";
        arrayContainer.appendChild(document.createElement("ol"));

        for (let i = 0; i < array.length; i++) {
          const listElement = document.createElement("li");
          listElement.setAttribute("id", array[i]);

          const spanElement = document.createElement("span");
          spanElement.appendChild(document.createTextNode(array[i]));
          listElement.appendChild(spanElement);
          arrayContainer.querySelector("ol").appendChild(listElement);
        }
      }
    }
  }

  xhttp.responseType = "json";
  xhttp.open("POST", "/algorithm/sorting/generate");
  xhttp.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
  xhttp.send(JSON.stringify({ arrayRange: arrayRange.value }));
}
