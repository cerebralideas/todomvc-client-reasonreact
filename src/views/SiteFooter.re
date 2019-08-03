[@react.component]
let make = () => {
	<footer className="info">
		<p>"Double-click to edit a todo" -> React.string</p>
		<p>"Created by " -> React.string
			<a href="http://github.com/cerebrl/">"Justin Lowery" -> React.string</a>
		</p>
		<p>"Inspired by " -> React.string
			<a href="http://todomvc.com">"TodoMVC" -> React.string</a>
		</p>
	</footer>
};
