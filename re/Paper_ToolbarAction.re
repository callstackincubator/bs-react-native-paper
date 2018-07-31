[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "ToolbarAction";

let make =
    (
      ~dark: bool=false,
      ~size: option(float)=?,
      ~icon: ReasonReact.reactElement,
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
          "size": fromOption(size),
          "icon": icon,
          "onPress": fromOption(onPress),
          "style": fromOption(style),
        }
      ),
    children,
  );
