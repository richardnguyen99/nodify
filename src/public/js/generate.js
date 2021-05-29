/* eslint-disable no-unused-vars */
let array;

function generateArray() {
  const arrayRange = document.querySelector("#arrayRange");
  const xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = () => {
    // eslint-disable-next-line eqeqeq
    if (this.readyState == 4 && this.status == 200) {
      array = xhttp.response.array;
    }
  };

  xhttp.responseType = "json";
  xhttp.open("POST", "/generate/array");
  xhttp.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
  xhttp.send(JSON.stringify({ arrayRange: arrayRange.value }));
}
