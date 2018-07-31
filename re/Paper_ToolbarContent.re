[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "ToolbarContent";

let make =
    (
      ~dark: bool=false,
      ~title: string,
      ~titleStyle: option(Rebolt.Style.t)=?,
      ~subtitle: option(string)=?,
      ~subtitleStyle: option(Rebolt.Style.t)=?,
      ~theme: option(Paper_ThemeProvider.appTheme)=?,
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
