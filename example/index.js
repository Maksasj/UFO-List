function triggerTraits() {
	const contentsElement = document.getElementById("traits-content");
	if (contentsElement.classList.contains("show")) {
		contentsElement.classList.remove("show");
	} else {
		contentsElement.classList.add("show");
	}
}
document.getElementById("traits").addEventListener("click", triggerTraits);

function triggerSituation() {
	const contentsElement = document.getElementById("situation-content");
	if (contentsElement.classList.contains("show")) {
		contentsElement.classList.remove("show");
	} else {
		contentsElement.classList.add("show");
	}
}
document
	.getElementById("situation")
	.addEventListener("click", triggerSituation);
