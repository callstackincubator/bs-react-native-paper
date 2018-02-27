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

module Button = {
  [@bs.module "react-native-paper"]
  external reactClass : ReasonReact.reactClass = "Button";

  let make =
    (
      ~disabled: option(bool)=?,
      ~compact: option(bool)=?,
      ~raised: option(bool)=?,
      ~primary: option(bool)=?,
      ~loading: option(bool)=?,
      ~dark: option(bool)=?,
      ~icon: option(Js.t({..}))=?,
      ~color: option(string)=?,
      ~children: option(
          [
            | `String(string)
            | `StringArray(array(string))
          ]
        )=?,
      ~style: option(
        [
          | `String(string)
          | `Object(Js.t({..}))
          | `String(string)
          | `StringArray(array(string))
          | `Int(int)
        ]
        )=?,
      ~theme: option(Js.t({..})),
      ~onPress
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "disabled": from_opt(disabled),
          "compact": from_opt(compact),
          "raised": from_opt(raised),
          "primary": from_opt(primary),
          "loading": from_opt(loading),
          "dark": from_opt(dark),
          "icon": from_opt(icon),
          "color": from_opt(color),
          "style": from_opt(style),
          "theme": from_opt(theme), 
          "onPress": from_opt(onPress)
        }
      ),
    children
  );
};