[@react.component]
let make = (
		~action: InputTypes.action,
		~todoText: option(string)=?,
		~todoId: option(string)=?,
		~flipEdit: option(('a => bool) => unit)=?, ()
	) => {
		let ( _, dispatch ) = React.useContext(Provider.context);
		let ( inputText, updateText ) =
			React.useState(() => {
				switch (todoText) {
				| None => ""
				| Some(x) => x
				};
			});
		let id = switch (todoId) {
			| None => ""
			| Some(x) => x
			};

		let handleChange = event => {
			let title = ReactEvent.Synthetic.target(event)##value;
			updateText(_ => title);
		};
		let handleSubmit = switch (action) {
			| Adding => event => {
				event -> ReactEvent.Synthetic.preventDefault;
				let title = ReactEvent.Form.target(event)##newTodo##value;
				dispatch(( AddTodo: StateTypes.action, title, "" ));
				updateText(_ => "");
			}
			| Editing => event => {
				event -> ReactEvent.Synthetic.preventDefault;
				let title = ReactEvent.Form.target(event)##newTodo##value;
				dispatch(( EditTodo: StateTypes.action, title, id ));
				updateText(_ => "");
				switch (flipEdit) {
					| None => ()
					| Some(x) => x(_ => false)
				};
			}
		};
		<form onSubmit={ handleSubmit }>
			<label style={ ReactDOMRe.Style.make(~position="fixed", ~top="-2em", ()) }
				htmlFor="newTodo">
					"Add a new todo" -> React.string
			</label>
			<input className={ action == Adding ? "new-todo" : "edit" }
				id="newTodo" type_="text"
				value={ inputText }
				onChange= { handleChange }
				placeholder="What needs to be done?" />
		</form>
	};
