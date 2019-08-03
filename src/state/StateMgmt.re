let initialState: StateTypes.state = Storage.getTodos();

let reducer = (
		state: StateTypes.state,
		(action: StateTypes.action, title: string, id: string)
	): StateTypes.state => {
		let newState: StateTypes.state = switch (action) {
		| AddTodo => {
			title != "" ?
				[
					{
						title: title,
						completed: false,
						id: Uuid.V4.uuidv4()
					},
					...state
				] :
				state;
		}
		| EditTodo => {
			title != "" ?
				state
					|> List.map((todo: StateTypes.todo): StateTypes.todo => {
						if (todo.id == id) {
							{
								title,
								completed: todo.completed,
								id: todo.id
							};
						} else {
							todo;
						}
					}) :
				state
					|> List.filter((todo: StateTypes.todo) =>
						todo.id != id
					);
		}
		| CompleteTodo => state
			|> List.map((todo: StateTypes.todo): StateTypes.todo => {
				if (todo.id == id) {
					{
						title: todo.title,
						completed: !todo.completed,
						id: todo.id
					};
				} else {
					todo;
				}
			});
		| DeleteTodo => state
			|> List.filter((todo: StateTypes.todo) =>
				todo.id != id
			)
		| CompleteAll => {
			let hasIncomplete = state |>
				List.exists((todo: StateTypes.todo) => todo.completed == false);
			switch (hasIncomplete) {
			| true => state |>
				List.map((todo: StateTypes.todo): StateTypes.todo =>
					{
						title: todo.title,
						completed: true,
						id: todo.id
					}
				)
			| false => state
				|> List.map((todo: StateTypes.todo): StateTypes.todo =>
					{
						title: todo.title,
						completed: false,
						id: todo.id
					}
				)
			};
		}
		| DeleteCompleted => state
			|> List.filter((todo: StateTypes.todo) =>
				todo.completed == false
			)
		};
	Storage.setTodos(newState);
	newState;
};
