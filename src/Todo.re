[@react.component]
let make = (~todo: StateMgmt.todo, ~dispatch) => {
	<li>
		<input type_="checkbox"
			id="completeTodo"
			onChange={ _ => dispatch(( CompleteTodo: StateMgmt.action, "", todo.id )); }
			checked={ todo.completed } />
		<label htmlFor="completeTodo">
			todo.title -> React.string
		</label>
		<button onClick={
			(_) => dispatch(( DeleteTodo: StateMgmt.action, "", todo.id));
			}>
			"X" -> React.string
		</button>
	</li>
};
