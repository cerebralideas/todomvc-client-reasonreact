type todo = {
	title: string,
	completed: bool,
	id: string
};
type state = {
	filter: string,
	todos: list(todo)
};
type action =
	| AddTodo
	| CompleteTodo
	| DeleteTodo;

let initialState: state = {
	filter: "all",
	todos: [
		{
			title: "Get started with ReasonReact",
			completed: false,
			id: Uuid.V4.uuidv4()
		}
	]
};

let reducer = (state, (action: action, title: string, id: string)) => {
	switch (action) {
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
				todos: state.todos |> List.map(todo => {
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
				todos: state.todos |> List.filter(todo => {
					todo.id != id;
				})
			}
		}
	}
};
