type todo = {
	title: string,
	completed: bool,
	id: string
};
type action =
	| AddTodo
	| CompleteTodo
	| DeleteTodo;

let initialTodo: todo = {
	title: "Get started with ReasonReact",
	completed: false,
	id: Uuid.V4.uuidv4()
};
let reducer = (state, (action: action, title: string, id: string)) => {
	switch (action) {
		| AddTodo => {
			[
				{
					title: title,
					completed: false,
					id: Uuid.V4.uuidv4()
				},
				...state
			];
		}
		| CompleteTodo => {
			state |> List.map(todo => {
				if (todo.title == id) {
					{
						title: todo.title,
						completed: !todo.completed,
						id: todo.id
					};
				} else {
					todo;
				}
			});
		}
		| DeleteTodo => {
			state |> List.filter(todo => {
				todo.id != id;
			});
		}
	}
};
