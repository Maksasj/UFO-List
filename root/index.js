function registerShowListeners(triggerId, contentId) {
	const triggers = document.querySelectorAll(`#${triggerId}`);
	const contents = document.querySelectorAll(`#${contentId}`);

	function trigger(element) {
		if (element.classList.contains("show")) {
			element.classList.remove("show");
		} else {
			element.classList.add("show");
		}
	}

	for (let i = 0; i < triggers.length; ++i) {
		triggers[i].addEventListener("click", () => {
			trigger(contents[i]);
		})
	}
}

registerShowListeners("traits-trigger", "traits-content")
registerShowListeners("situation-trigger", "situation-content")
