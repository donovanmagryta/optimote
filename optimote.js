
function programpeaks() {
  var vidy = document.getElementById("videoPlayer");
  var peakpoints = vidy.currentTime;
  vidy.pause();
  comment = prompt("Tag the part starting here! For example: SCARY or FUNNY");
  alert("Peak trigger point saved!");
  console.log("trigger point saved at" + peakpoints + "type = " + comment);
}


let currentVideoIndex = 0;
var user = prompt("Hi Tester. What are your initials?");
var time = "";
var bpm = "";
var pred = "";
var value = "0";
var dataa = [
   [user, time, bpm, pred]
];
function download_csv() {
    var csv = 'USER,TIME,BPM,PRED\n';
    dataa.forEach(function(row) {
            csv += row.join(',');
            csv += "\n";
    });

    console.log(csv);
    var hiddenElement = document.createElement('a');
    hiddenElement.href = 'data:text/csv;charset=utf-8,' + encodeURI(csv);
    hiddenElement.target = '_blank';
    filename = user + "-biodata.csv";
    hiddenElement.download = filename;
    hiddenElement.click();
}

function playVideo(file) {
   const player = document.getElementById("videoPlayer");
   currentVID.setAttribute("src", URL.createObjectURL(file));
   player.load();
   player.play();
}

function playlocalVID() {
  const selectedFiles = document.getElementById("newlocalFILE");
  currentVideoIndex = 0;
  if (selectedFiles.files.length === 0) {
    return;
  }
  const src = selectedFiles.files[0];
  playVideo(src);

}

var number = "";
var num = "";
document.onkeyup = function(event) {
   if ((event.ctrlKey) && (event.altKey) && (event.key)) {
     //alert(event.key)
   var digit = event.key;
   number += digit;
   }
   if ((event.altKey) && (event.key === "z")) {
     //alert("z pressed")
     var num = number;
     num = num.replace("Enter", "");
     var digit = ""
     var reset = ""
     number = reset;//clear string

if (num.startsWith("bpm")) {
  bpm = num.slice(3);
  console.log("HEART BPM = " + bpm);
  var HR = ("💓" + bpm);
//if ctrl + digit is pressed, add it to string using +=. When ctrl + key Z is called, set string as number and clear string.
var statbtn = document.getElementsByClassName('stats');
statbtn[0].innerHTML = HR; }
if (num.startsWith("pred")) { pred = num.slice(4); console.log("Prediction = " + pred) }
if (num.startsWith("time")) { time = num.slice(4); console.log("Time = " + time) }
if (num.startsWith("appencsv")) { dataa.push([user,time,bpm,pred]); console.log("BIODATA LOGGED") }
if (num.startsWith("quieter")) {
 var vidy = document.getElementById("videoPlayer");
volum = (vid.volume);
vid.volume = (volum - 10);
var statuss = document.getElementsByClassName('statuss');
var n = volum.toFixed(2);
statuss[0].innerHTML = "volume adapted to " + n + "%";
console.log("quieter")
}
if (num.startsWith("louder")) {
var vidy = document.getElementById("videoPlayer");
volum = (vid.volume);
vid.volume = (volum + 10);
var statuss = document.getElementsByClassName('statuss');
var n = volum.toFixed(2);
statuss[0].innerHTML = "volume adapted to " + n + "%";
console.log("louder")
}
if (num.startsWith("faster")) {
var vidy = document.getElementById("videoPlayer");
speeed = (vidy.playbackRate); vidy.playbackRate = (speeed + 0.04);
var statuss = document.getElementsByClassName('statuss');
var n = speeed.toFixed(2);
statuss[0].innerHTML = "tempo adapted to " + n;
console.log("faster") }
if (num.startsWith("slower")) {
 var vidy = document.getElementById("videoPlayer");
 speeed = (vidy.playbackRate); vidy.playbackRate = (speeed - 0.04);
 var statuss = document.getElementsByClassName('statuss');
 var n = speeed.toFixed(2);
 statuss[0].innerHTML = "tempo adapted to " + n;
 console.log("slower")
 }
if (num.startsWith("peak")) { //CURRENTLY SET IN ARDUINO TO THRILL PEAK ONLY - ADD SEPARATE LOGIC FOR CALM MODE!
  var vidy = document.getElementById("videoPlayer");
  vidy.currentTime = peakpoints;

  vidy.play(); // NOT NEEDED??

  /*const currentVID = document.getElementById("currentVID");
  const selectedFiles = document.getElementById("newlocalFILE");
  currentVideoIndex = currentVideoIndex >= selectedFiles.files.length - 1
    ? 0 : currentVideoIndex + 1;

  const selectedLocalVID = selectedFiles.files[currentVideoIndex];
  playVideo(selectedLocalVID);*/

var statuss = document.getElementsByClassName('statuss');
statuss[0].innerHTML = "jumped to peak clip";
console.log("peak") }

}

else {
  //sleep(1) //if user is typing, pause sensor autotyping.
}
}
