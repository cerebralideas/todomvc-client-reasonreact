[@react.component]
let make = (~state, ~dispatch) => {
	let addTodo = event => {
		event -> ReactEvent.Synthetic.preventDefault;
		let title = ReactEvent.Form.target(event)##newTodo##value;
		dispatch(( AddTodo: StateMgmt.action, title, "" ));
	};
	let todoEls = state |> List.map((todo: StateMgmt.todo) => {
		<li key={ todo.id }>
			<label onClick={
				(_) => dispatch(( CompleteTodo, "", todo.id ));
				}>
				<input type_="checkbox"
					defaultChecked={ todo.completed } />
				todo.title -> React.string
			</label>
			<button onClick={
				(_) => dispatch(( DeleteTodo, "", todo.id));
				}>
				"X" -> React.string
			</button>
		</li>
	});
	<div>
		<form onSubmit={ addTodo }>
			<label htmlFor="newTodo"> "Add a new todo" -> React.string </label><br/>
			<input id="newTodo" type_="text" />
		</form>
		<ul>
			todoEls -> Array.of_list -> React.array
		</ul>
	</div>;
};
