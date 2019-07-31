[@react.component]
let make = (~activeCount: int) => {
	let itemWord = activeCount == 1 ? "item" -> React.string : "items" -> React.string;
	let stringForCount = { activeCount != 0 ? string_of_int(activeCount) -> React.string : "No" -> React.string };
	let spc = " " -> React.string;

	<span className="todo-count">
		<strong>stringForCount</strong> spc itemWord spc "left" -> React.string
	</span>
};
