/** Welcome to your first Reason React application!

  If you are familiar with Javascript and React, there should be 3 things that
  may be new to you:

  * Modules
  * Types
  * Pipe operator (|>)

  ## Modules

  Just like Javascript, Reason has modules too. Reason modules are similar to
  Javascript, but they have a few differences:

    * Reason modules are first-class, like functions, and they are defined with
      a special syntax: `module Module_name = { ... };`

    * Modules are global!

  ## Types

  Reason is strongly and staticaly typed, meaning you have to define the type
  of data you work with beforehand. It is a common practice to have a small
  module that handles one specific type, so we normally call that type `t`.
  This makes it easier to find the main type on any module. It is normally
  `Module_name.t`, and any auxiliary type typically has a name, like
  `Module_name.aux_type_name`.

  ## Pipe operator

  If you haven't used the `|>` operator before, it's called _pipe_, and it lets
  you put the output of a function as the input of another one like this:

  ```reason
  add(1, 2)
  |> duplicate
  ```

  which is equals to writing:

  ```reason
  let three = add(1, 2);
  duplicate(three);
  ```
*/
ReactDOMRe.renderToElementWithId(<Components.ToDo />, "app");
