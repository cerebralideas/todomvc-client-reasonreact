[@react.component]
let make = () => {
	let ( state, _ ) = React.useContext(Provider.context);

	let filteredTodos: list(StateTypes.todo) =
		ReasonReactRouter.useUrl()
		|> (url) =>
			switch (url.hash) {
			| "all" => state
			| "active" => state
				|> List.filter(
					(todo: StateTypes.todo) => todo.completed == false
				)
			| "completed" => state
				|> List.filter(
					(todo: StateTypes.todo) => todo.completed == true
				)
			| _ => state
			};
	<section className="main">
		<CompleteAll />
		<ul className="todo-list">
			(
				filteredTodos
				|> List.map((todo: StateTypes.todo) =>
					<Todo key={ todo.id } todo />
				)
			)
			-> Array.of_list
			-> React.array
		</ul>
	</section>
};
