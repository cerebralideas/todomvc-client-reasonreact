type todo = {
  title: string,
  completed: bool,
  id: string,
};
type state = list(todo);
type action =
  | AddTodo
  | EditTodo
  | CompleteTodo
  | DeleteTodo
  | CompleteAll
  | DeleteCompleted;
