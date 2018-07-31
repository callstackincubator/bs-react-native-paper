[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "ToolbarBackAction";

let make =
    (
      ~dark: bool=false,
      ~style: option(Rebolt.Style.t)=?,
      ~onPress: option(Rebolt.RNEvent.NativeEvent.t => unit)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.(
        {
          "dark": dark,
          "onPress": fromOption(onPress),
          "style": fromOption(style),
        }
      ),
    children,
  );
