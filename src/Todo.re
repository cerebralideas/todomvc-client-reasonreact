[@react.component]
let make = (~todo: StateTypes.todo) => {
	let ( _, dispatch ) = React.useContext(Provider.context);

	<li>
		<input type_="checkbox"
			id={ "completeTodo" ++ todo.id }
			onChange={
				_ => dispatch(( CompleteTodo: StateTypes.action, "", todo.id ));
			}
			checked={ todo.completed } />
		<label htmlFor={ "completeTodo" ++ todo.id }>
			todo.title -> React.string
		</label>
		<button onClick={
			(_) => dispatch(( DeleteTodo: StateTypes.action, "", todo.id));
			}>
			"X" -> React.string
		</button>
	</li>
};
