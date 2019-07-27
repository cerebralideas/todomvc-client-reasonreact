let initialState: StateTypes.state = {
	filter: Storage.getFilter(),
	todos: Storage.getTodos()
};

let reducer = (state: StateTypes.state, (action: StateTypes.action, title: string, id: string)): StateTypes.state => {
		let newState: StateTypes.state = switch (action) {
			| AddTodo => {
				{
					filter: state.filter,
					todos: [
						{
							title: title,
							completed: false,
							id: Uuid.V4.uuidv4()
						},
						...state.todos
					]
				}
			}
			| CompleteTodo => {
				{
					filter: state.filter,
					todos: state.todos |> List.map((todo: StateTypes.todo): StateTypes.todo => {
						if (todo.id == id) {
							{
								title: todo.title,
								completed: !todo.completed,
								id: todo.id
							};
						} else {
							todo;
						}
					})
				}
			}
			| DeleteTodo => {
				{
					filter: state.filter,
					todos: state.todos |> List.filter((todo: StateTypes.todo) =>
						todo.id != id
					)
				}
			}
			| CompleteAll => {
				let hasIncomplete = state.todos |>
					List.exists((todo: StateTypes.todo) => todo.completed == false);
				{
					filter: state.filter,
					todos: switch (hasIncomplete) {
						| true => state.todos |> List.map((todo: StateTypes.todo): StateTypes.todo =>
								{
									title: todo.title,
									completed: true,
									id: todo.id
								}
							)
						| false => state.todos |> List.map((todo: StateTypes.todo): StateTypes.todo =>
								{
									title: todo.title,
									completed: false,
									id: todo.id
								}
							)
					}
				}
			}
			| DeleteCompleted => {
				{
					filter: state.filter,
					todos: state.todos |> List.filter((todo: StateTypes.todo) =>
						todo.completed == false
					)
				}
			}
		};
	Storage.setFilter(newState.filter);
	Storage.setTodos(newState.todos)
	newState;
};
