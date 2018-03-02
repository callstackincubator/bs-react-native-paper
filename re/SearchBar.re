

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "SearchBar";

let make =
  (
    ~placeholder: option(string)=?,
    ~value: option(string),
    ~icon: option(ReasonReact.reactElement)=?,
    ~theme: option(Js.t({..}))=?,
    ~style: option(BsReactNative.Style.t)=?,
    ~onChangeText: option(string => unit),
    ~onIconPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
    children
  ) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=
    Js.Nullable.(
      {
        "placeholder": from_opt(placeholder),
        "value": from_opt(value),
        "icon": from_opt(icon),
        "onChangeText": from_opt(onChangeText),
        "onIconPress": from_opt(onIconPress),
        "theme": from_opt(theme),
        "style": from_opt(style)
      }
    ),
  children
);
