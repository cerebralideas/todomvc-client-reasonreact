[@react.component]
let make = () => {
	let ( _, dispatch ) = React.useContext(Provider.context);

	let addTodo = event => {
		event -> ReactEvent.Synthetic.preventDefault;
		let title = ReactEvent.Form.target(event)##newTodo##value;
		dispatch(( AddTodo: StateTypes.action, title, "" ));
	};
	<header className="header">
		<h1>"todos" -> React.string</h1>
		<form onSubmit={ addTodo }>
			<label style={ ReactDOMRe.Style.make(~position="fixed", ~top="-2em", ()) }
				htmlFor="newTodo">
					"Add a new todo" -> React.string
			</label>
			<input className="new-todo" id="newTodo" type_="text"
				placeholder="What needs to be done?" />
		</form>
	</header>
};
