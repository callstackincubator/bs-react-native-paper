[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "ToolbarContent";

let make =
    (
      ~dark: bool=false,
      ~title: string,
      ~titleStyle: option(BsReactNative.Style.t)=?,
      ~subtitle: option(string)=?,
      ~subtitleStyle: option(BsReactNative.Style.t)=?,
      ~theme: option(Paper_ThemeProvider.theme)=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.(
        {
          "dark": dark,
          "onPress": fromOption(onPress),
          "title": title,
          "titleStyle": fromOption(titleStyle),
          "subtitle": fromOption(subtitle),
          "subtitleStyle": fromOption(subtitleStyle),
          "style": fromOption(style),
          "theme": fromOption(theme),
        }
      ),
    children,
  );
