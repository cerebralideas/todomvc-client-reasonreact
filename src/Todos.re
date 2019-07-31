[@react.component]
let make = () => {
	let ( state, _ ) = React.useContext(Provider.context);

	let filteredTodos: list(StateTypes.todo) =
		ReasonReactRouter.useUrl() |>
			(url) => switch (url.hash) {
				| "all" => state.todos
				| "active" => state.todos |>
					List.filter((todo: StateTypes.todo) =>
						todo.completed == false)
				| "completed" => state.todos |>
					List.filter((todo: StateTypes.todo) =>
						todo.completed == true)
				| _ => state.todos
			};
	<section className="main">
		<CompleteAll />
		<ul className="todo-list">
			(
				filteredTodos |>
					List.map((todo: StateTypes.todo) =>
						<Todo key={ todo.id } todo />
					)
			) -> Array.of_list -> React.array
		</ul>
	</section>
};
