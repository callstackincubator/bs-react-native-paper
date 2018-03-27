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
          "placeholder": Js.Undefined.fromOption(placeholder),
          "value": Js.Undefined.fromOption(value),
          "icon": Js.Undefined.fromOption(icon),
          "onChangeText": Js.Undefined.fromOption(onChangeText),
          "onIconPress": Js.Undefined.fromOption(onIconPress),
          "theme": Js.Undefined.fromOption(theme),
          "style": Js.Undefined.fromOption(style)
        }
      ),
    children
  );
