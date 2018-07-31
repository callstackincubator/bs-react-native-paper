[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Divider";

let make =
    (
      ~inset: bool=false,
      ~theme: option(Paper_ThemeProvider.appTheme)=?,
      ~style: option(Rebolt.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.(
        {
          "inset": inset,
          "style": fromOption(style),
          "theme": fromOption(theme),
        }
      ),
    children,
  );
