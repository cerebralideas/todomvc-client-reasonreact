[@react.component]
let make = () => {
	let ( todos, addTodo ) = React.useState(() => [ "Get started with ReasonReact" ]);
	let addTodo = event => {
		ReactEvent.Synthetic.preventDefault(event);
		let title = ReactEvent.Form.target(event)##newTodo##value;
		addTodo(todos => [ title, ...todos ]);
	};
	<div>
		<form onSubmit={ addTodo }>
			<label htmlFor="newTodo">{ React.string("Add a new todo") }</label><br/>
			<input id="newTodo" type_="text" />
		</form>
		<ul>
			{
				ReasonReact.array(
					Array.of_list(
						List.map(todo => {
							<li>{ React.string(todo) }</li>
						}, todos)
					)
				)
			}
		</ul>
	</div>;
};
