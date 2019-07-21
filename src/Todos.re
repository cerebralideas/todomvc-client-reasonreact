[@react.component]
let make = (~todos: list(StateMgmt.todo), ~dispatch) => {
	<ul>
		(
			todos |>
				List.map((todo: StateMgmt.todo) => {
					<Todo key={ todo.id } todo dispatch />
				})
		) -> Array.of_list -> React.array
	</ul>
};
