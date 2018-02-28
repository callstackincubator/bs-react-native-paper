type jsUnsafe;

external toJsUnsafe : 'a => jsUnsafe = "%identity";

let wrap_bool = (b: option(bool)) =>
  switch b {
  | Some(value) => Js.Nullable.return(Js.Boolean.to_js_boolean(value))
  | None => Js.Nullable.undefined
  };

let unwrap_value =
    (
      r: [<
        | `Int(int)
        | `IntArray(array(int))
        | `String(string)
        | `StringArray(array(string))
        | `Float(float)
        | `FloatArray(array(float))
        | `Date(Js.Date.t)
        | `ReactElement(ReasonReact.reactElement)
        | `Object(Js.t({..}))
      ]
    ) =>
  switch r {
  | `String(s) => toJsUnsafe(s)
  | `Int(i) => toJsUnsafe(i)
  | `StringArray(a) => toJsUnsafe(a)
  | `IntArray(a) => toJsUnsafe(a)
  | `Float(f) => toJsUnsafe(f)
  | `FloatArray(a) => toJsUnsafe(a)
  | `Date(d) => toJsUnsafe(d)
  | `ReactElement(e) => toJsUnsafe(e)
  | `Object(o) => toJsUnsafe(o)
  };

let option_map = (fn, option) =>
  switch option {
  | Some(value) => Some(fn(value))
  | None => None
  };
  