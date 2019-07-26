[@react.component]
let make = () => {
	let ( state, _ ) = React.useContext(Provider.context);

	let filteredTodos: list(StateMgmt.todo) =
		ReasonReactRouter.useUrl() |>
			(url) => switch (url.hash) {
				| "all" => state.todos
				| "active" => state.todos |>
					List.filter((todo: StateMgmt.todo) =>
						todo.completed == false)
				| "completed" => state.todos |>
					List.filter((todo: StateMgmt.todo) =>
						todo.completed == true)
				| _ => state.todos
			};

	<ul>
		(
			filteredTodos |>
				List.map((todo: StateMgmt.todo) =>
					<Todo key={ todo.id } todo />
				)
		) -> Array.of_list -> React.array
	</ul>
};
