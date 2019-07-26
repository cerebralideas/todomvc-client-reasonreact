[@react.component]
let make = () => {
	<ul>
		<li>
			<a href="#all"
				onClick={ _ => ReasonReactRouter.push("#all") }>
				"All" -> React.string
			</a>
		</li>
		<li>
			<a href="#active"
				onClick={ _ => ReasonReactRouter.push("#active") }>
				"Active" -> React.string
			</a>
		</li>
		<li>
			<a href="#completed"
				onClick={ _ => ReasonReactRouter.push("#completed") }>
				"Completed" -> React.string
			</a>
		</li>
	</ul>
};
