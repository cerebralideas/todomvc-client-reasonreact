type todo = {
	title: string,
	completed: bool,
	id: string
};
type action =
	| AddTodo
	| CompleteTodo;

[@react.component]
let make = () => {
	let initialTodo: todo = {
		title: "Get started with ReasonReact",
		completed: false,
		id: Uuid.V4.uuidv4()
	};
	let ( state, dispatch ) = React.useReducer((state, (action, title)) => {
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
						if (todo.title == title) {
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
			}
		},
		[ initialTodo ]
	);
	let addTodo = event => {
		ReactEvent.Synthetic.preventDefault(event);
		let title = ReactEvent.Form.target(event)##newTodo##value;
		dispatch(( AddTodo, title ));
	};
	let completeTodo = (event, todo) => {
		dispatch(( CompleteTodo, todo.title ));
	};
	<div>
		<form onSubmit={ addTodo }>
			<label htmlFor="newTodo">{ React.string("Add a new todo") }</label><br/>
			<input id="newTodo" type_="text" />
		</form>
		<ul>
			{
				React.array(
					Array.of_list(
						state |> List.map(todo => {
							<li key={ todo.id }>
								<label onClick={ event => completeTodo(event, todo) }>
									<input type_="checkbox"
										defaultChecked={ todo.completed } />
									{ React.string(todo.title) }
								</label>
							</li>
						})
					)
				)
			}
		</ul>
	</div>;
};
