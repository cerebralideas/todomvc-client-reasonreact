[@react.component]
let make = (~state: StateMgmt.state, ~dispatch) => {
	let url = ReasonReactRouter.useUrl();
	let filteredTodos: list(StateMgmt.todo) = switch (url.hash) {
		| "all" => state.todos
		| "active" => state.todos |>
			List.filter((todo: StateMgmt.todo) => todo.completed == false)
		| "completed" => state.todos |>
			List.filter((todo: StateMgmt.todo) => todo.completed == true)
		| _ => state.todos
	};

	Js.log(state.todos);

	<>
		<AddTodo dispatch />
		<Todos todos={ filteredTodos } dispatch />
		<Footer />
	</>
};
