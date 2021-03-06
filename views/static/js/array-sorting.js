function sort(array) {
  const xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      const arrayElement = document.getElementById("array");

      arrayElement.innerHTML = "";

      for (let i = 0; i < xhttp.response.sortedArray.length; i++) {
        arrayElement.innerHTML += `
          <svg width="10" height="${xhttp.response.sortedArray[i]}">
            <rect width="10" height="${xhttp.response.sortedArray[i]}" style="fill:rgb(0,0,255);" />
          </svg>
        `
      }
    }
  };

  xhttp.responseType = "json";
  xhttp.open("POST", "/algorithm/sorting");
  xhttp.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
  xhttp.send(JSON.stringify({"array": array}));
}
