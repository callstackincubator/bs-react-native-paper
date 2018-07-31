[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "TouchableRipple";

let make =
    (
      ~borderless: bool=false,
      ~background: option(Js.t({..}))=?,
      ~disabled: bool=false,
      ~rippleColor: option(string)=?,
      ~underlayColor: option(string)=?,
      ~style: option(Rebolt.Style.t)=?,
      ~theme: option(Paper_ThemeProvider.appTheme)=?,
      ~onPress: option(Rebolt.RNEvent.NativeEvent.t => unit)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.(
        {
          "borderless": borderless,
          "background": fromOption(background),
          "disabled": disabled,
          "rippleColor": fromOption(rippleColor),
          "underlayColor": fromOption(underlayColor),
          "theme": fromOption(theme),
          "onPress": fromOption(onPress),
          "style": fromOption(style),
        }
      ),
    children,
  );
