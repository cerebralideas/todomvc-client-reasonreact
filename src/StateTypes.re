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
	| DeleteTodo
	| CompleteAll
	| DeleteCompleted;
