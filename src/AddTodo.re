[@react.component]
let make = () => {
	let ( _, dispatch ) = React.useContext(Provider.context);

	let addTodo = event => {
		event -> ReactEvent.Synthetic.preventDefault;
		let title = ReactEvent.Form.target(event)##newTodo##value;
		dispatch(( AddTodo: StateMgmt.action, title, "" ));
	};

	<form onSubmit={ addTodo }>
		<label htmlFor="newTodo">
				"Add a new todo" -> React.string
		</label>
		<br/>
		<input id="newTodo" type_="text" />
	</form>
};
